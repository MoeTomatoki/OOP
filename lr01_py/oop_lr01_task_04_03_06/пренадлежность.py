# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 7
#
# Выполнил: Ермолаев К.А.
# Группа: ПИН-б-о-22-1
# E-mail: dj-profi.ermolaev@yandex.ru


class ПищущаяПринадлежность:
    """Класс ПищущаяПринадлежность содержит общие атрибуты для принадлежностей.

    Дочерние классы будут их конкретизировать.
    """

    def __init__(self):
        """Конструктор класса.

        Инициализирует атрибуты принадлежности (значения по умолчанию).
        """
        self.название = "Заготовка"
        self.чернила = "шариковые"  # шариковые, гелевые, грифель
        self.корпус = "пластик"   # пластик, оргстекло или кедр

        self.цена = 0

    def __str__(self):
        """Вернуть информацию о ручке: название, чернила, корпус, цена.

        Формат вывода:

        Принадлежность: Шариковая ручка | Цена: 25.00 р.
        Чернила: шариковые | Корпус: пластик
        """

        return f'Принадлежность: {self.название} | Цена: {self.цена:.2f} р.\n' \
               f'   Чернила: {self.чернила} | Корпус: {self.корпус}'

    def формирование(self):
        print('Формируем заказ')

    def упаковать(self):
        print('Упаковываем в фирменную упаковку')

class Карандаш(ПищущаяПринадлежность):
    """Класс для карандашей."""

    def __init__(self):
        super().__init__()

        self.название = "Карандаш"
        self.чернила = "грифель"
        self.корпус = "кедр"
        self.цена = 10

class Ручка(ПищущаяПринадлежность):
    """Общий класс для ручек."""

    def __init__(self, название, чернила, корпус, цена):
        super().__init__()

        self.название = название
        self.чернила = чернила
        self.корпус = корпус
        self.цена = цена


class ШариковаяРучка(Ручка):
    """Класс для шариковых ручек."""

    def __init__(self):
        super().__init__("Шариковая ручка", "шариковые", "оргстекло", 25)


class ГелеваяРучка(Ручка):
    """Класс для гелевых ручек."""

    def __init__(self):
        super().__init__("Гелевая ручка", "гелевые", "пластик", 15)