import unittest
import stream_line_receiver as slr


class TypewiseTest(unittest.TestCase):

  def test_receiver(self):
      self.assertTrue(
        slr.read_data(
          'receiver/output_data.txt'
        ) is True
      )


if __name__ == '__main__':
  unittest.main()
