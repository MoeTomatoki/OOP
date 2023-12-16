import unittest
from io import StringIO
from unittest.mock import patch
from пренадлежность import ПищущаяПринадлежность, Карандаш, ШариковаяРучка, ГелеваяРучка
from терминал import *
from заказ import *

class TestTerminal(unittest.TestCase):

    def setUp(self):
        self.терминал = Терминал()

    def test_str(self):
        expected_output = f'{Терминал.КОМПАНИЯ}, {Терминал.ВЕРСИЯ}'
        self.assertEqual(str(self.терминал), expected_output)

    def test_show_menu(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            self.терминал.показать_меню()
            output = fake_out.getvalue()

        self.assertIn(Терминал.КОМПАНИЯ, output)
        self.assertIn('Добро пожаловать!', output)

    def test_order_process(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            with patch('builtins.input', return_value='0'):
                self.терминал.отображать_меню = False
                self.терминал.заказ = Заказ()
                self.терминал.заказ.добавить(Карандаш())
                self.терминал.обработать_команду('0')
            output = fake_out.getvalue()

        self.assertIn('Заказ подтвержен.', output)
        self.assertIsNotNone(self.терминал.заказ)

    def test_cancel_order(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            with patch('builtins.input', return_value='-1'):
                self.терминал.обработать_команду('-1')
            output = fake_out.getvalue()

        self.assertIn('Ваш заказ отменён', output)
        self.assertIsNone(self.терминал.заказ)

    def test_add_accessory_to_order(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            with patch('builtins.input', return_value='0'):
                self.терминал.обработать_команду('1')
            output = fake_out.getvalue()

        self.assertIn('Принадлежность Карандаш добавлена!', output)
        self.assertIsNotNone(self.терминал.заказ)
        self.assertEqual(len(self.терминал.заказ.заказанные_принадлежности), 1)
        self.assertIsInstance(self.терминал.заказ.заказанные_принадлежности[0], Карандаш)

    def test_invalid_command(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            self.терминал.обработать_команду('invalid')
        output = fake_out.getvalue()

        self.assertIn("Не могу распознать команду! Проверьте ввод.", output)

    def test_payment_process(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            with patch('builtins.input', side_effect=['20', '0']):
                self.терминал.отображать_меню = False
                self.терминал.заказ = Заказ()
                self.терминал.заказ.добавить(Карандаш())
                self.терминал.принять_оплату()
            output = fake_out.getvalue()

        self.assertIn('Сумма заказа:', output)
        self.assertIn('Вы внесли 20.00 р. Сдача: 10.00 р.', output)

    def test_insufficient_payment(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            with patch('builtins.input', side_effect=['5', '0']):
                with self.assertRaises(ValueError):
                    self.терминал.отображать_меню = False
                    self.терминал.заказ = Заказ()
                    self.терминал.заказ.добавить(Карандаш())
                    self.терминал.принять_оплату()
            output = fake_out.getvalue()

        self.assertIn('Сумма заказа:', output)
        self.assertIn("Оплата не удалась. Заказ будет отменен.", output)

if __name__ == '__main__':
    unittest.main()
