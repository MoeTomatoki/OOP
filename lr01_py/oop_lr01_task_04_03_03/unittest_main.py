import unittest
from deposit import deposits


class TestDepositSelection(unittest.TestCase):

    def assertDepositAlmostEqual(self, deposit, expected, initial_sum, period):
        self.assertAlmostEqual(deposit.get_profit(initial_sum, period), expected["profit"], places=2)
        self.assertAlmostEqual(deposit.get_sum(initial_sum, period), expected["sum"], places=2)
        self.assertEqual(deposit.currency, expected["currency"])

    def test_deposit_selection(self):
        initial_sum = 1000
        period = 12

        matched_deposits = []
        for deposit in deposits:
            try:
                deposit._check_user_params(initial_sum, period)
                matched_deposits.append(deposit)
            except AssertionError as err:
                pass

        self.assertEqual(len(matched_deposits), 3)

        expected_results = [
            {
                "name": "Сохраняй",
                "profit": 50.00,
                "sum": 1050.00,
                "currency": "руб."
            },
            {
                "name": "Бонусный 2",
                "profit": 50.00,
                "sum": 1050.00,
                "currency": "руб."
            },
            {
                "name": "С капитализацией",
                "profit": 51.16,
                "sum": 1051.16,
                "currency": "руб."
            }
        ]

        for i, deposit in enumerate(matched_deposits):
            with self.subTest(deposit=deposit):
                self.assertEqual(deposit.name, expected_results[i]["name"])
                self.assertDepositAlmostEqual(deposit, expected_results[i], initial_sum, period)


if __name__ == '__main__':
    unittest.main()
