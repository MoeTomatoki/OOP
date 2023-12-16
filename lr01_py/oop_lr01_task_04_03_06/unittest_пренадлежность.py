import unittest
from io import StringIO
from unittest.mock import patch
from пренадлежность import ПищущаяПринадлежность, Карандаш, ШариковаяРучка, ГелеваяРучка

class TestPrinadlezhnost(unittest.TestCase):

    def test_pishchushchaya_prinadlezhnost_str(self):
        принадлежность = ПищущаяПринадлежность()
        expected_output = 'Принадлежность: Заготовка | Цена: 0.00 р.\n   Чернила: шариковые | Корпус: пластик\n'

        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(принадлежность)
            output = fake_out.getvalue()

        self.assertEqual(output, expected_output)

    def test_karandash_init(self):
        карандаш = Карандаш()
        self.assertEqual(карандаш.название, 'Карандаш')
        self.assertEqual(карандаш.чернила, 'грифель')
        self.assertEqual(карандаш.корпус, 'кедр')
        self.assertEqual(карандаш.цена, 10)

    def test_karandash_str(self):
        карандаш = Карандаш()
        expected_output = 'Принадлежность: Карандаш | Цена: 10.00 р.\n   Чернила: грифель | Корпус: кедр\n'

        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(карандаш)
            output = fake_out.getvalue()

        self.assertEqual(output, expected_output)

    def test_sharikovaya_ruchka_init(self):
        шариковая_ручка = ШариковаяРучка()
        self.assertEqual(шариковая_ручка.название, 'Шариковая ручка')
        self.assertEqual(шариковая_ручка.чернила, 'шариковые')
        self.assertEqual(шариковая_ручка.корпус, 'оргстекло')
        self.assertEqual(шариковая_ручка.цена, 25)

    def test_sharikovaya_ruchka_str(self):
        шариковая_ручка = ШариковаяРучка()
        expected_output = 'Принадлежность: Шариковая ручка | Цена: 25.00 р.\n   Чернила: шариковые | Корпус: оргстекло\n'

        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(шариковая_ручка)
            output = fake_out.getvalue()

        self.assertEqual(output, expected_output)

    def test_gelevaya_ruchka_init(self):
        гелевая_ручка = ГелеваяРучка()
        self.assertEqual(гелевая_ручка.название, 'Гелевая ручка')
        self.assertEqual(гелевая_ручка.чернила, 'гелевые')
        self.assertEqual(гелевая_ручка.корпус, 'пластик')
        self.assertEqual(гелевая_ручка.цена, 15)

    def test_gelevaya_ruchka_str(self):
        гелевая_ручка = ГелеваяРучка()
        expected_output = 'Принадлежность: Гелевая ручка | Цена: 15.00 р.\n   Чернила: гелевые | Корпус: пластик\n'

        with patch('sys.stdout', new_callable=StringIO) as fake_out:
            print(гелевая_ручка)
            output = fake_out.getvalue()

        self.assertEqual(output, expected_output)

if __name__ == '__main__':
    unittest.main()
