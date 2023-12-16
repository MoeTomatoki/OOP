# Программирование на языке высокого уровня (Python).
# Задание №4.3.4 Вариант 7
#
# Выполнил: Ермолаев К.А.
# Группа: ПИН-б-о-22-1
# E-mail: dj-profi.ermolaev@yandex.ru

import json

class Stack:
    def __init__(self, *args):
        """
        Инициализация пустого стека.
        """
        self.items = [*args]

    def is_empty(self):
        """
        Проверка на пустоту стека.
        """
        return len(self.items) == 0
    
    def unshift(self, item):
        """
        Добавляет элемент в начало стека.
        """
        self.items.insert(0, item)

    def shift(self):
        """
        Забирает первый элемент стека и возвращает его.
        """
        if not self.is_empty():
            return self.items.pop(0)
        else:
            raise IndexError("Стек пуст.")

    def push(self, item):
        """
        Добавляет элемент в конец стека.
        """
        self.items.append(item)

    def pop(self):
        """
        Забирает последний элемент стека и возвращает его.
        """
        if not self.is_empty():
            return self.items.pop()
        else:
            raise IndexError("Стек пуст.")

    def last_item(self):
        """
        Возвращает элемент с конца стека без его удаления.
        """
        if not self.is_empty():
            return self.items[-1]
        else:
            raise IndexError("Стек пуст.")

    def length(self):
        """
        Возвращает количество элементов в стеке.
        """
        return len(self.items)

    def __str__(self):
        """
        Возвращает строковое представление стека.
        """
        return str(self.items)

    @classmethod
    def from_string(cls, str_value):
        """
        Создает объект на основе строки str_value.
        """
        items = [int(item) for item in str_value.split(',')]
        return cls(*items)

    def save(self, filename):
        """
        Сохраняет объект в JSON-файл filename.
        """
        with open(filename, 'w') as file:
            json.dump({'items': self.items}, file)

    def load(self, filename):
        """
        Загружает объект из JSON-файла filename.
        """
        with open(filename, 'r') as file:
            data = json.load(file)
            self.items = data['items']
