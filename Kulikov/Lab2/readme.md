# Обоснование проектных решений

В лабораторной работе разработана система классов для моделирования следующих геометрических фигур:

- **Прямоугольник**
- **Трапеция**
- **Правильный пятиугольник**

## Структура Point

Для хранения координат вершин фигуры

## Абстрактный класс Shape

Был создан абстрактный класс Shape, который содержит следующие чисто виртуальные методы:

- **move()** \- перемещает фигуру в заданную точку
- **turn()** \- поворачивает фигуру на заданный угол
- **scale()** \- масштабирует фигуру на заданный коэффициент
- **setColor()**\- устанавливает цвет для фигуры
- **getColor()**\- возвращает цвет фигуры
- **getId()**\- возвращает уникальный идентификатор фигуры 

Также класс Shape содержит protected поле-счетчик sCounter для однозначной идентификации каждого объекта.

## Класс Rectangle
Наследуется от базового класса Shape и переопределяет его виртуальные методы для работы с прямоугольником, также содержит приватный метод **positionCentre()** для определения центра фигуры. В классе происходит перегрузка оператора вывода в поток для корректного вывода объекта. В качестве полей содержит цвет, id и 4 точки, соответствующие вершинам прямоугольника. Имеет один конструктор по 4 точкам.

## Класс Trapeze

Наследуется от базового класса Shape и переопределяет его виртуальные методы для работы с трапецией, также содержит приватный метод **positionCentre()** для определения "центра" фигуры. В классе происходит перегрузка оператора вывода в поток для корректного вывода объекта. В качестве полей содержит цвет, id и 4 точки, соответствующие вершинам трапеции. Имеет один конструктор по 4 точкам.

## Класс RegularPentagon

Наследуется от базового класса Shape и переопределяет его виртуальные методы для работы с правильным пятиугольником, также содержит приватный метод **positionCentre()** для определения "центра" фигуры. В классе происходит перегрузка оператора вывода в поток для корректного вывода объекта. В качестве полей содержит цвет, id и 5 точек, соответствующие вершинам правильного пятиугольника. Имеет один конструктор по 5 точкам

## Управление созданием объектов

Был создан базовый класс **exc** от которого наследуются три класса - исключения для соответствующих фигур:

- **badRectangleException**\- выводит сообщение о неправильном прямоугольнике
- **badTrapezeException**\-выводит сообщение о неправильной трапеции
- **badPentagonException**\-выводит сообщение о неправильном пятиугольнике

В конструкторе каждого класса фигуры происходит проверка на валидность, в случае некорректных данных происходит выброс исключения, которые обрабатываются в блоке try-catch в основной части программы. Это означает, что при попытке создать объект с неверными данными, объект не будет создан.
>