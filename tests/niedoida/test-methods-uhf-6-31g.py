import unittest
from niedoida_test_case import NiedoidaTestCase

class NiedoidaTestCaseMethodsuhf631g(NiedoidaTestCase):

    def setUp(self):
        self.data = self.run_calculations("test-methods-uhf-6-31g")

    def test_energy(self):
        self.assertAlmostEqual(self.data.scfenergies[0], -1058.23967722202, 2)

if __name__ == '__main__':
    unittest.main()