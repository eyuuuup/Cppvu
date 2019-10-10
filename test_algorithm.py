import unittest
import algorithm

class TestAlgorithm(unittest.TestCase):
    def test_invalid_zero(self):
        creditCard = "0"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)
    
    def test_invalid_letter(self):
        creditCard = "abcdefghijklnmop"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)
    
    def test_invalid_empty(self):
        creditCard = ""
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)
    
    def test_invalid_big(self):
        creditCard = "47759282896363153213123523123245231245"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_invalid_small(self):
        creditCard = "47754"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)   

    def test_visaValid1(self):
        creditCard = "4775928289636315"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)
    
    def test_visaValid2(self):
        creditCard = "4413841180104606"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)

    def test_visaInvalid1(self):
        creditCard = "4127604351047031"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_visaInvalid2(self):
        creditCard = "4877604355547031"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_masterValid1(self):
        creditCard = "5355772805740242"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)
    
    def test_masterValid2(self):
        creditCard = "5302191850521932"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)

    def test_masterInvalid1(self):
        creditCard = "5302191850521933"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_masterInvalid2(self):
        creditCard = "5555772805740242"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_americanValid1(self):
        creditCard = "370846443993249"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)
    
    def test_americanValid2(self):
        creditCard = "375039821712150"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)

    def test_americanInvalid1(self):
        creditCard = "345891882996246"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_americanInvalid2(self):
        creditCard = "344891882996246"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_discoverValid1(self):
        creditCard = "6011281755167541"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)
    
    def test_discoverValid2(self):
        creditCard = "6011361952059921"
        result = algorithm.process(creditCard)
        self.assertEqual(result, True)

    def test_discoverInvalid1(self):
        creditCard = "60114461952059921"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)

    def test_discoverInvalid2(self):
        creditCard = "6011561952059921"
        result = algorithm.process(creditCard)
        self.assertEqual(result, False)