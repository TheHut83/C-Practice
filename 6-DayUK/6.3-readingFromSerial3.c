#include <windows.h>
#include <stdio.h>
#include <string.h>

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
            int x_value, y_value, button_state;

            if (sscanf(read_buf, "%d %d %d", &x_value, &y_value, &button_state) == 3) {
                printf("Ready to Data Analysis:\n");
                printf("X_Value: %d\n", x_value);
                printf("Y_Value: %d\n", y_value);
                printf("ButtonState: %d\n", button_state);
                fprintf(fptr,"%s%d%c%d%c%d%c","Ready-To-Data-Analysis: DataLog:",x_value,' ',y_value,' ',button_state,'\n');
            }
        }

        // Introduce a delay of 1 second (1000 milliseconds)
        Sleep(500);
    }

    //Close the serial port
    CloseHandle(hSerial);
    return 0;
}
