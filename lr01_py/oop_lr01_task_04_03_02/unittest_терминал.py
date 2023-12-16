import unittest
from пицца import *
from заказ import *
from терминал import *
from unittest.mock import patch
from io import StringIO


class TestTerminalMethods(unittest.TestCase):

    def setUp(self):
        self.terminal = Терминал()
        pass

    def test_show_menu(self):
        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            self.terminal.показать_меню()
            output = fake_out.getvalue()

        self.assertIn(Терминал.КОМПАНИЯ, output)
        self.assertIn('Добро пожаловать!', output)


    def test_process_command_cancel_order(self):
        self.terminal.отображать_меню = False
        self.terminal.заказ = Заказ()
        self.terminal.обработать_команду('-1')
        self.assertIsNone(self.terminal.заказ)

    def test_process_command_confirm_order(self):
        self.terminal.отображать_меню = False
        self.terminal.заказ = Заказ()
        self.terminal.заказ.добавить(ПиццаПепперони())
        self.assertIsNone(self.terminal.обработать_команду('0'))

    def test_process_command_add_pizza(self):
        self.terminal.отображать_меню = False
        self.terminal.обработать_команду('1')
        self.assertEqual(len(self.terminal.заказ.заказанные_пиццы), 1)
        self.assertEqual(self.terminal.заказ.заказанные_пиццы[0].название, 'Пепперони')

    def test_process_command_invalid_input(self):
        self.terminal.отображать_меню = False
        self.assertIsNone(self.terminal.обработать_команду('invalid'))

    def test_calculate_change(self):
        self.terminal.заказ = Заказ()
        self.terminal.заказ.добавить(ПиццаПепперони())
        self.assertEqual(self.terminal.рассчитать_сдачу(400), 50)
        with self.assertRaises(ValueError):
            self.terminal.рассчитать_сдачу(300)

    def test_accept_payment(self):
        self.terminal.заказ = Заказ()
        with patch("builtins.input", return_value="1000"):
            with self.assertRaises(Exception):
                self.терминал.заказ = Заказ()
                self.терминал.заказ.добавить(ПиццаПепперони())
                self.terminal.принять_оплату()


if __name__ == '__main__':
    unittest.main()
