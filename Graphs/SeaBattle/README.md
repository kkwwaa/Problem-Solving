# Sea Battle

[Description!](https://acmp.ru/asp/do/index.asp?main=task&id_course=2&id_section=21&id_topic=51&id_problem=653)

Everyone knows the fascinating game "Battleship" Nowadays, you can play Battleship not only with your desk neighbor but also with a computer. The game with a computer takes place on a rectangular field of arbitrary sizes N×M, where N is the number of rows and M is the number of columns. 
The World Championship in Battleship is approaching. It is planned to broadcast it in real-time: showing the map with ships and displaying the statistics: the number of intact, damaged, and destroyed ships on the field. A program is needed to calculate the statistics.A ship on the field is a connected shape made up of one or more adjacent cells that share a side. Ships can be of any shape and size!

**Return three numbers separated by spaces:**
- **number of intact ships**
- **number of damaged ships**
- **number of destroyed ships**

[My Solution](https://github.com/kkwwaa/Problem-Solving/blob/main/Graphs/SeaBattle/solution.cpp)
***
### Ru Notes

- С помощью BFS определяем количество кораблей
- Внутри с помощью условий определяем тип корабля
- Возвращаем триплет с увеличенным значением вида найденного корабля
