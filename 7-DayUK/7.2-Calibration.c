#include <windows.h>
#include <stdio.h>
#include <string.h>
float calibration(float sensorValue);

int main() {
    FILE *fptr;
    fptr = fopen("dataLog.txt","a");
    HANDLE hSerial;
    DCB dcbSerialParams = { 0 };
    COMMTIMEOUTS timeouts = { 0 };

    // Open the serial port (COM1)
    //hSerial = CreateFile("COM12", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    //hSerial = CreateFile("COM11", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    hSerial = CreateFile(
            "\\\\.\\COM11",     // address of name of the communications device
            GENERIC_READ | GENERIC_WRITE,          // access (read-write) mode
            0,                  // share mode
            NULL,               // address of security descriptor
            OPEN_EXISTING,      // how to create
            0,                  // file attributes
            NULL                // handle of file with attributes to copy
    );
    if (hSerial == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error opening serial port\n");
        GetLastError();
        return 1;
    }

    // Set device parameters
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error getting device state\n");
        CloseHandle(hSerial);
        return 1;
    }
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error setting device parameters\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Set timeouts
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if (!SetCommTimeouts(hSerial, &timeouts)) {
        fprintf(stderr, "Error setting timeouts\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Read data from the serial port
    char read_buf[256];
    float x_raw_data[10];
    float y_raw_data[10];
    float b_raw_data[10];
    int data_counter=0;
    DWORD num_bytes_read;
    while (1) {
        if (!ReadFile(hSerial, read_buf, sizeof(read_buf), &num_bytes_read, NULL)) {
            fprintf(stderr, "Error reading from serial port\n");
            CloseHandle(hSerial);
            return 1;
        }
        if (num_bytes_read > 0) {
            read_buf[num_bytes_read] = '\0'; // Null-terminate the received data
            //printf("Received data: %s\n", read_buf);


            // Extract three integers from the received data
            float x_value, y_value, button_state;

            if (sscanf(read_buf, "%f %f %f", &x_value, &y_value, &button_state) == 3) {
                printf("Ready to Data Analysis:\n");
                printf("X_Value: %f\n", x_value);
                printf("Y_Value: %f\n", y_value);
                printf("ButtonState: %f\n", button_state);
                fprintf(fptr,"%s%d%c%s%f%c%f%c%f%c","Input:",data_counter,' ',"Raw X Y Z Value: DataLog:",x_value,' ',y_value,' ',button_state,'\n');

                x_raw_data[data_counter]=x_value;
                y_raw_data[data_counter]=y_value;
                b_raw_data[data_counter]=button_state;
            }
        }
        data_counter++;
        printf("Checking for Data Counter=%d\n",data_counter);
        float x_total=0;
        float y_total=0;
        float b_total=0;
        float x_avg=0;
        float y_avg=0;
        float b_avg=0;
        float cali_x,cali_y,cali_b;
        if(data_counter==10){
            for(int i=0; i<10; i++){
                x_total += x_raw_data[i];
                y_total += y_raw_data[i];
                b_total += b_raw_data[i];
            }
            x_avg= x_total/10;
            y_avg= y_total/10;
            b_avg= b_total/10;
            printf("--------------Average--------------\n");
            printf("Average Value X=%f : Y=%f : ButtonState=%f\n",x_avg,y_avg,b_avg);
            printf("--------------Average End--------------\n");
            fprintf(fptr,"%s%f%c%f%c%f%c","Average X Y Z Value: DataLog:",x_avg,' ',y_avg,' ',b_avg,'\n');

            cali_x = calibration(x_avg);
            cali_y = calibration(y_avg);
            cali_b = calibration(b_avg);

            printf("--------------Calibrated Value--------------\n");
            printf("Calibrated Mapped Value Cali_X = %f : Cali_Y = %f : Cali_b = %f\n",cali_x,cali_y,cali_b);
            printf("--------------Calibration Complete--------------\n");
            fprintf(fptr,"%s%f%c%f%c%f%c","Calibrated X Y Z Value: DataLog:",cali_x,' ',cali_y,' ',cali_b,'\n');
            data_counter=0;

        }

        // Introduce a delay of 1 second (1000 milliseconds)
        Sleep(500);
    }

    //Close the serial port
    CloseHandle(hSerial);
    return 0;
}
//x=510
//y=502

float calibration(float sensorValue){
    float fromLow=246;
    float fromHigh=777;
    float toLow=0;
    float toHigh=255;

    float mappedValue=(sensorValue - fromLow) * (toHigh - toLow) / (fromHigh - fromLow)+ toLow;
    return mappedValue;
}