"""
Code contained in this and attached files is pep8 compliant.
To generate HTML documentation for the tested tasks use the
following command in the directory containing all source files:

    pydoc -w ./

"""
import ex2l2_Popiel
import ex5l2_Popiel
import unittest
import math


class TestSquareRoot(unittest.TestCase):
    def setUp(self):
        return super().setUp()

    def test1(self):
        program = ex2l2_Popiel
        self.assertEqual(program.sqrt(0), 0)

    def test2(self):
        program = ex2l2_Popiel
        self.assertEqual(program.sqrt(1), 1)
        self.assertEqual(program.sqrt(2), 1)
        self.assertEqual(program.sqrt(3), 1)
        self.assertEqual(program.sqrt(4), 2)

    def test3(self):
        program = ex2l2_Popiel
        self.assertEqual(program.sqrt(5), 2)
        self.assertEqual(program.sqrt(6), 2)
        self.assertEqual(program.sqrt(8), 2)
        self.assertEqual(program.sqrt(9), 3)

    def test4(self):
        program = ex2l2_Popiel
        for i in range(100, 200):
            self.assertEqual(program.sqrt(i), int(math.floor(math.sqrt(i))))

    def test5(self):
        program = ex2l2_Popiel
        with self.assertRaises(TypeError):
            program.sqrt("text")
        with self.assertRaises(ValueError):
            program.sqrt(-5)


class TestCompression(unittest.TestCase):
    def setUp(self):
        return super().setUp()

    def test1(self):
        program = ex5l2_Popiel
        test = "ssdakzzzzzzz.,dasdasdzxaaaaa,"

        testres = [(2, 's'), (1, 'd'), (1, 'a'), (1, 'k'), (7, 'z'), (1, '.'),
                   (1, ','), (1, 'd'), (1, 'a'), (1, 's'), (1, 'd'), (1, 'a'),
                   (1, 's'), (1, 'd'), (1, 'z'), (1, 'x'), (5, 'a'), (1, ',')]
        self.assertEqual(program.compress(test), testres)

    def test2(self):
        program = ex5l2_Popiel
        test = ";ds,lf;dslg.dasdkasf.z"

        testres = [(1, ';'), (1, 'd'), (1, 's'), (1, ','), (1, 'l'), (1, 'f'),
                   (1, ';'), (1, 'd'), (1, 's'), (1, 'l'), (1, 'g'), (1, '.'),
                   (1, 'd'), (1, 'a'), (1, 's'), (1, 'd'), (1, 'k'), (1, 'a'),
                   (1, 's'), (1, 'f'), (1, '.'), (1, 'z')]
        self.assertEqual(program.compress(test), testres)

    def test3(self):
        program = ex5l2_Popiel
        test = "zxcz.aa \
rrrrgg \
bbjjjja \
aaaddcc"
        testres = [(1, 'z'), (1, 'x'), (1, 'c'), (1, 'z'), (1, '.'), (2, 'a'),
                   (1, ' '), (4, 'r'), (2, 'g'), (1, ' '), (2, 'b'), (4, 'j'),
                   (1, 'a'), (1, ' '), (3, 'a'), (2, 'd'), (2, 'c')]
        self.assertEqual(program.compress(test), testres)


if __name__ == '__main__':
    unittest.main()
