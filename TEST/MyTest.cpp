#include <iostream>

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int sumPrimesInArray(int arr[][30], int numRows, int numCols) {
    int sum = 0;

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (isPrime(arr[i][j])) {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

int main() {
    FILE* filePtr = nullptr;

    // Tên tệp tin
    const char* fileName = "Input.txt";

    // Mở tệp tin
    if (fopen_s(&filePtr, fileName, "r") == 0) {
        int numRows, numCols;

        // Đọc số hàng và số cột từ file
        fscanf_s(filePtr, "%d %d", &numRows, &numCols);

        // Sử dụng mảng hai chiều để lưu trữ dữ liệu
        int data[20][30];

        // Đọc dữ liệu từ file vào mảng hai chiều
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                fscanf_s(filePtr, "%d", &data[i][j]);
            }
        }

        // In dữ liệu ra màn hình
        std::cout << "Du lieu doc tu file:" << std::endl;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Gọi hàm sumPrimesInArray
        int result = sumPrimesInArray(data, numRows, numCols);

        std::cout << "Tong cac so nguyen to la: " << result << std::endl;


        // Xuất kết quả ra file mới
        FILE* outputFilePtr = nullptr;
        const char* outputFileName = "OutputSum.txt";
        if (fopen_s(&outputFilePtr, outputFileName, "w") == 0) {
            fprintf(outputFilePtr, "%d\n", result);
            fclose(outputFilePtr);
        }
        else {
            std::cerr << "Khong the tao file sumsntoutput.txt." << std::endl;
        }



        // Đóng tệp tin khi không cần sử dụng nữa
        fclose(filePtr);
    }
    else {
        // Xử lý khi mở tệp tin thất bại
        std::cerr << "Khong the mo tap tin." << std::endl;
    }

    return 0;
}
