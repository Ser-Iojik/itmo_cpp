#include <iostream>
using namespace std;

int main(void) {
    freopen("turtle.in", "r", stdin);
    freopen("turtle.out", "w", stdout);

    int h, w, i, j;
    cin >> h >> w;
    // Создаём исходный массив и его копию
    int a[h][w], copy_a[h][w];

    // Заполняем массив
    for (i = 0; i < h; i++) {  
        for (j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    // В копию записываем нижнее левое значение исходного массива
    copy_a[h-1][0] = a[h-1][0];

    // Заполняем суммой ячейки левого столбца нового массива copy_a
    for (i = 1; i < h; i++) {
        copy_a[h - i - 1][0] = copy_a[h - i][0] + a[h - i - 1][0];
    }

    // Заполняем суммой ячейки нижней строки нового массива copy_a
    for (j = 0; j < w - 1; j++) {
        copy_a[h - 1][j + 1] = copy_a[h - 1][j] + a[h - 1][j + 1];
    }

    // Сравниваем значение справа и сверху во втором массиве
    // Если где-то значение больше, то суммируем его
    // со значением из исходной матрицы
    for (i = h - 2; i >= 0; i--) {
        for (j = 1; j < w; j++ ) {
            // Если значение справа больше, то
            // суммируем его со значением из исходной матрицы
            if (copy_a[i + 1][j] > copy_a[i][j - 1]) {
                copy_a[i][j] = copy_a[i + 1][j] + a[i][j];
            }
            // Если значение сверху больше, то
            // суммируем его со значением из исходной матрицы
            else {
                copy_a[i][j] = copy_a[i][j - 1] + a[i][j];
            }
        }
    }
    // Выводим в консоль крайнюю правую ячейку новой матрицы, это и есть ответ
    cout << copy_a[0][w - 1];
}