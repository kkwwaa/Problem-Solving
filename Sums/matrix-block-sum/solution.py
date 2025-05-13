class Solution(object):
    def matrixBlockSum(self, mat, k):
        #получаем размеры матрицы h-стррок и w-столбцов
        h, w = len(mat), len(mat[0])

        #создаем матрицу для интегрального изображения (h x w, заполнена 0)
        integral_image = [[0 for y in range(w)] for x in range(h)]

        #строим интегральное изображение
        for y in range(h):
            summation = 0 #сумма элементов в текущей строке
            for x in range(w):
                #добавляем текущий элемент к сумме строки
                summation += mat[y][x]
                #интегральное значение = сумма строки + сумма предыдущей строки (если есть)
                integral_image[y][x] = summation
                if y>0:
                    integral_image[y][x] += integral_image[y-1][x]

        #создаем выходную матрицу для хранения сумм прямоугольников
        output_image = [[0 for y in range(w)] for x in range(h)]

        #вычисляем сумму для каждого прямоугольника с ценитром (y, x)
        for y in range(h):
            for x in range(w):
                #определяем границы прямоугольника: от y-k до y+k, от x-k до x+k (по усл)
                #ограничиваем границы, чтобы не выйти за пределы матрицы
                min_row, max_row = max(0, y-k), min(h-1, y+k)
                min_col, max_col = max(0, x-k), min(w-1, x+k)

                #базоовая сумма = значение в правом нижнеем углу прямоугольника (D)
                output_image[y][x] = integral_image[max_row][max_col]

                #вычитаем лишнюю часть сверху (В)
                if min_row > 0:
                    output_image[y][x] -= integral_image[min_row-1][max_col]

                # вычитаем лишнюю часть снизу (С)
                if min_col > 0:
                    output_image[y][x] -= integral_image[max_row][min_col-1]

                # добавляем вычтенную 2 раза область (А)
                if min_col > 0 and min_row > 0:
                    output_image[y][x] += integral_image[min_row-1][min_col-1]

        #возвращаем матрицу с суммами
        return(output_image)
