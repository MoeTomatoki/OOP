import unittest
from io import StringIO
from unittest.mock import patch
from пренадлежность import *
from заказ import Заказ

class TestOrder(unittest.TestCase):

    def setUp(self):
        self.order = Заказ()

    def test_order_str(self):
        pencil = Карандаш()
        pen = ШариковаяРучка()
        self.order.добавить([pencil, pen])

        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(self.order)

        expected_output = (
            "Заказ №1\n"
            "1. Принадлежность: Карандаш | Цена: 10.00 р.\n"
            "   Чернила: грифель | Корпус: кедр\n"
            "2. Принадлежность: Шариковая ручка | Цена: 25.00 р.\n"
            "   Чернила: шариковые | Корпус: оргстекло"
        )

        self.assertEqual(fake_out.getvalue().strip(), expected_output)

    def test_order_add(self):
        pencil = Карандаш()
        pen = ШариковаяРучка()
        self.order.добавить([pencil, pen])

        self.assertEqual(len(self.order.заказанные_принадлежности), 2)

    def test_order_sum(self):
        pencil = Карандаш()
        pen = ШариковаяРучка()
        self.order.добавить([pencil, pen])

        self.assertEqual(self.order.сумма(), 35)

    def test_order_execute(self):
        pencil = Карандаш()
        pen = ШариковаяРучка()
        self.order.добавить([pencil, pen])

        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            self.order.выполнить()

        expected_output = (
            "1. Карандаш\n"
            "Формируем заказ\n"
            "Упаковываем в фирменную упаковку\n"
            "2. Шариковая ручка\n"
            "Формируем заказ\n"
            "Упаковываем в фирменную упаковку\n"
            "Заказ №1 готов! Спасибо за покупку!"
        )

        self.assertEqual(fake_out.getvalue().strip(), expected_output)


class TestWritingUtensils(unittest.TestCase):

    def test_pencil_str(self):
        pencil = Карандаш()
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(pencil)

        expected_output = (
            "Принадлежность: Карандаш | Цена: 10.00 р.\n"
            "   Чернила: грифель | Корпус: кедр"
        )

        self.assertEqual(fake_out.getvalue().strip(), expected_output)

    def test_ballpoint_pen_str(self):
        pen = ШариковаяРучка()
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(pen)

        expected_output = (
            "Принадлежность: Шариковая ручка | Цена: 25.00 р.\n"
            "   Чернила: шариковые | Корпус: оргстекло"
        )

        self.assertEqual(fake_out.getvalue().strip(), expected_output)

    def test_gel_pen_str(self):
        gel_pen = ГелеваяРучка()
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(gel_pen)

        expected_output = (
            "Принадлежность: Гелевая ручка | Цена: 15.00 р.\n"
            "   Чернила: гелевые | Корпус: пластик"
        )

        self.assertEqual(fake_out.getvalue().strip(), expected_output)


if __name__ == '__main__':
    unittest.main()
