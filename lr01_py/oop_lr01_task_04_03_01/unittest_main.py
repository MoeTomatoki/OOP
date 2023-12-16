import unittest
from roman import Roman

class RomanTestCase(unittest.TestCase):
    def setUp(self):
        self.roman_X = Roman("XXI")
        self.roman_V = Roman(8)

    def test_init_with_roman(self):
        self.assertEqual(self.roman_X.arabic, 21)

    def test_init_with_arabic(self):
        self.assertEqual(str(self.roman_V), "VIII")

    def test_init_with_invalid_value(self):
        with self.assertRaises(TypeError):
            r = Roman(3.14)

    def test_addition(self):
        result = self.roman_X + self.roman_V
        self.assertEqual(result.arabic, 29)
        self.assertEqual(str(result), "XXIX")

    def test_subtraction(self):
        result = self.roman_X - self.roman_V
        self.assertEqual(result.arabic, 13)
        self.assertEqual(str(result), "XIII")

    def test_multiplication(self):
        result = self.roman_X * self.roman_V
        self.assertEqual(result.arabic, 168)
        self.assertEqual(str(result), "CLXVIII")

    def test_floor_division(self):
        result = self.roman_X // self.roman_V
        self.assertEqual(result.arabic, 2)
        self.assertEqual(str(result), "II")

    def test_to_arabic(self):
        result = Roman.to_arabic("XXXIV")
        self.assertEqual(result, 34)

    def test_to_roman(self):
        result = Roman.to_roman(1994)
        self.assertEqual(result, "MCMXCIV")

    def test_add_arabic(self):
        result = self.roman_X + 7
        self.assertEqual(result.arabic, 28)
        self.assertEqual(str(result), "XXVIII")

    def test_subtract_arabic(self):
        result = self.roman_X - 5
        self.assertEqual(result.arabic, 16)
        self.assertEqual(str(result), "XVI")

    def test_multiply_arabic(self):
        result = self.roman_X * 4
        self.assertEqual(result.arabic, 84)
        self.assertEqual(str(result), "LXXXIV")

    def test_floor_divide_arabic(self):
        result = self.roman_X // 3
        self.assertEqual(result.arabic, 7)
        self.assertEqual(str(result), "VII")

    def test_to_roman_negative(self):
        with self.assertRaises(ValueError):
            Roman.to_roman(-10)

if __name__ == "__main__":
    unittest.main()
