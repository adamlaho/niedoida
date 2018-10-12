import unittest
from niedoida_test_case import NiedoidaTestCase

class NiedoidaTestCaseMethodsbeckeccpvtz(NiedoidaTestCase):

    def setUp(self):
        self.data = self.run_calculations("test-methods-becke-cc-pvtz")

    def test_energy(self):
        self.assertAlmostEqual(self.data.scfenergies[0], -2070.80604493697, 2)

if __name__ == '__main__':
    unittest.main()