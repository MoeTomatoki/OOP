import unittest
from main import Stack


class TestStackMethods(unittest.TestCase):
    def setUp(self):
        self.stack = Stack()

    def test_is_empty(self):
        self.assertTrue(self.stack.is_empty())
        self.stack.push(1)
        self.assertFalse(self.stack.is_empty())

    def test_push_pop(self):
        self.stack.push(1)
        self.assertEqual(self.stack.pop(), 1)

    def test_shift_unshift(self):
        self.stack.unshift(1)
        self.assertEqual(self.stack.shift(), 1)

    def test_last_item(self):
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(self.stack.last_item(), 2)

    def test_length(self):
        self.assertEqual(self.stack.length(), 0)
        self.stack.push(1)
        self.assertEqual(self.stack.length(), 1)
        self.stack.pop()
        self.assertEqual(self.stack.length(), 0)

    def test_from_string(self):
        str_value = "1,2,3,4,5"
        stack_from_str = Stack.from_string(str_value)
        self.assertEqual(stack_from_str.items, [1, 2, 3, 4, 5])

    def test_save_load(self):
        filename = "test_stack.json"
        self.stack.push(1)
        self.stack.save(filename)
        loaded_stack = Stack()
        loaded_stack.load(filename)
        self.assertEqual(loaded_stack.items, [1])

if __name__ == '__main__':
    unittest.main()
