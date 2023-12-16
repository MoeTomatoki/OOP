import unittest
from unittest.mock import patch
from io import StringIO
from пицца import *
from заказ import Заказ


class TestPizza(unittest.TestCase):
    def setUp(self):
        self.пепперони = ПиццаПепперони()
        self.барбекю = ПиццаБарбекю()
        self.дарыМоря = ПиццаДарыМоря()

    def test_пиццаПепперони(self):
        self.assertEqual(self.пепперони.название, 'Пепперони')
        self.assertEqual(self.пепперони.цена, 350)

    def test_пиццаБарбекю(self):
        self.assertEqual(self.барбекю.название, 'Барбекю')
        self.assertEqual(self.барбекю.цена, 450)

    def test_пиццаДарыМоря(self):
        self.assertEqual(self.дарыМоря.название, 'Дары моря')
        self.assertEqual(self.дарыМоря.цена, 550)

    def test_добавить(self):
        order = Заказ()
        order.добавить(self.пепперони)
        order.добавить(self.барбекю)
        order.добавить(self.дарыМоря)
        self.assertEqual(len(order.заказанные_пиццы), 3)

    @patch("sys.stdout", new_callable=StringIO)
    def test_выполнить(self, mock_stdout):
        order = Заказ()
        order.добавить(self.пепперони)
        order.добавить(self.барбекю)
        order.добавить(self.дарыМоря)

        expected_output = (
            "1. Пицца: Пепперони | Цена: 350.00 р.\n"
            "Тесто: тонкое Соус: томатный\n"
            "Начинка: пепперони, сыр моцарелла\n"
            "2. Пицца: Барбекю | Цена: 450.00 р.\n"
            "Тесто: тонкое Соус: барбекю\n"
            "Начинка: бекон, ветчина, зелень, сыр моцарелла\n"
            "3. Пицца: Дары моря | Цена: 550.00 р.\n"
            "Тесто: пышное Соус: тар-тар\n"
            "Начинка: кальмары, креветки, мидии, сыр моцарелла\n"
            "Заказ №1 готов! Приятного аппетита!\n"
        )

        with patch("time.sleep", side_effect=lambda x: None):
            order.выполнить()

        self.assertEqual(mock_stdout.getvalue(), expected_output)

    def test_сумма(self):
        order = Заказ()
        order.добавить(self.пепперони)
        order.добавить(self.барбекю)
        order.добавить(self.дарыМоря)
        self.assertEqual(order.сумма(), 1350.00)


if __name__ == '__main__':
    unittest.main()

