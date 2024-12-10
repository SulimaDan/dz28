#include <iostream>
#include <cstdlib> // Для rand()

template<typename T>
class Matrix {
private:
    T** data;
    size_t rows, cols;

    void allocateMemory() {
        data = new T * [rows];
        for (size_t i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    void freeMemory() {
        for (size_t i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
        allocateMemory();
    }

    ~Matrix() {
        freeMemory();
    }

    void inputFromKeyboard() {
        std::cout << "Enter matrix elements:\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    void fillRandom(T minValue, T maxValue) {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = minValue + rand() % (maxValue - minValue + 1);
            }
        }
    }

    void print() const {
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    size_t rows = 3, cols = 3;
    Matrix<int> mat1(rows, cols);
    Matrix<int> mat2(rows, cols);

    mat1.fillRandom(1, 10);
    mat2.fillRandom(1, 10);

    std::cout << "Matrix 1:\n";
    mat1.print();

    std::cout << "\nMatrix 2:\n";
    mat2.print();

    Matrix<int> sum = mat1 + mat2;
    std::cout << "\nMatrix Sum:\n";
    sum.print();

    return 0;
}
