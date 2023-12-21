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


    def test_сумма(self):
        order = Заказ()
        order.добавить(self.пепперони)
        order.добавить(self.барбекю)
        order.добавить(self.дарыМоря)
        self.assertEqual(order.сумма(), 1350.00)


if __name__ == '__main__':
    unittest.main()

