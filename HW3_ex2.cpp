//Создайте шаблонный класс матрица.Необходимо реализовать динамическое выделение памяти, очистку памяти,
//заполнение матрицы с клавиатуры, заполнение случайны - ми значениями, отображение матрицы, арифметические
//операции с помощью перегруженных операторов(+, –, *, / ), поиск минимального и максимального элемента.

#include <iostream>

template <typename T>
class Matrix {
    T** data;
    int rows;
    int cols;

public:
    Matrix() : rows{ 0 }, cols{ 0 }, data{ nullptr } {}

    Matrix(int r, int c) : rows{ r }, cols{ c } {
        data = new T * [rows];
        for (int i{}; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
        data = new T * [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i{}; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void input() {
        std::cout << "Введите элементы матрицы:\n";
        for (int i{}; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cin >> data[i][j];
            }
        }
    }

    void random() {
        srand(time(0));
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                data[i][j] = rand() % 100;
            }
        }
    }

    void print() {
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "Ошибка! Размерности матриц не совпадают.\n";
            return Matrix<T>();
        }
        Matrix<T> result(rows, cols);
        for (int i{}; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "Ошибка! Размерности матриц не совпадают.\n";
            return Matrix<T>();
        }
        Matrix<T> result(rows, cols);
        for (int i{}; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "Ошибка! Размерности матриц не совпадают.\n";
            return Matrix<T>();
        }
        Matrix<T> result(rows, cols);
        for (int i{}; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] * other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator/(const T& scalar) const {
        if (scalar == 0) {
            std::cerr << "Ошибка! Деление на ноль.\n";
            return Matrix<T>();
        }
        Matrix<T> result(rows, cols);
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                result.data[i][j] = data[i][j] / scalar;
            }
        }
        return result;
    }

    T findMin() const {
        T min = data[0][0];
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                if (data[i][j] < min) {
                    min = data[i][j];
                }
            }
        }
        return min;
    }

    T findMax() const {
        T max = data[0][0];
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                if (data[i][j] > max) {
                    max = data[i][j];
                }
            }
        }
        return max;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Matrix<int> matrix1(2, 3); 
    Matrix<int> matrix2(2, 3); 

    std::cout << "Ввод элементов матрицы 1:\n";
    matrix1.input();

    std::cout << "Заполнение матрицы 2 случайными значениями:\n";
    matrix2.random();

    std::cout << "Матрица 1:\n";
    matrix1.print();

    std::cout << "Матрица 2:\n";
    matrix2.print();

    std::cout << "Сумма матриц:\n";
    (matrix1 + matrix2).print();

    std::cout << "Разность матриц:\n";
    (matrix1 - matrix2).print();

    std::cout << "Произведение матриц:\n";
    (matrix1 * matrix2).print();

    std::cout << "Деление матрицы 1 на скаляр 2:\n";
    (matrix1 / 2).print();

    std::cout << "Минимальный элемент матрицы 1: " << matrix1.findMin() << std::endl;
    std::cout << "Максимальный элемент матрицы 1: " << matrix1.findMax() << std::endl;

    return 0;
}