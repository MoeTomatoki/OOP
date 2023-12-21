import unittest
from io import StringIO
from unittest.mock import patch
from пренадлежность import *
from заказ import Заказ


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
