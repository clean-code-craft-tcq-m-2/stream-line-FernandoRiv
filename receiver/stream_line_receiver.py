import pandas as pd


def split_values(lines):
  headers = []
  data_a = []
  data_b = []
  data_c = []
  for line in lines:
    splited_line = line.split(',')
    if (len(headers) == 0):
      headers = [splited_line[0], splited_line[2], splited_line[4]]
    data_a.append(int(splited_line[1]))
    data_b.append(int(splited_line[3]))
    data_c.append(int(splited_line[5].replace('\n', '')))
  return headers, data_a, data_b, data_c


def max_values(data):
  return max(data)


def min_values(data):
  return min(data)


# Ref https://www.geeksforgeeks.org/how-to-calculate-moving-averages-in-python/
def simple_moving_average(data):
  window_size = 5
  numbers_series = pd.Series(data)
  windows = numbers_series.rolling(window_size)
  moving_average = windows.mean()
  moving_average_list = moving_average.tolist()
  data = moving_average_list[window_size - 1:]
  return data


def print_max_values(headers, max_a, max_b, max_c):
  print(headers[0] + " Max value ===> " + str(max_a) + "\n"
        + headers[1] + "Max value ===> " + str(max_b) + "\n"
        + headers[2] + "Max value ===> " + str(max_c))


def print_min_values(headers, min_a, min_b, min_c):
  print(headers[0] + " Min value ===> "  + str(min_a) + "\n"
        + headers[1] + "Min value ===> " + str(min_b) + "\n"
        + headers[2] + "Min value ===> " + str(min_b))


def print_moving_average(headers, min_a, min_b, min_c):
  print(headers[0] + " SMA value ===> " + str(min_a) + "\n"
        + headers[1] + "SMA value ===> " + str(min_b) + "\n"
        + headers[2] + "SMA value ===> " + str(min_b))


def read_data(stream):
  with open(stream) as f:
    lines= f.readlines()
  headers, data_a, data_b, data_c=split_values(lines)
  max_a = max_values(data_a)
  max_b = max_values(data_b)
  max_c = max_values(data_c)
  min_a = min_values(data_a)
  min_b = min_values(data_b)
  min_c = min_values(data_c)
  sma_a = simple_moving_average(data_a)
  sma_b = simple_moving_average(data_b)
  sma_c = simple_moving_average(data_c)
  print_max_values(headers, max_a, max_b, max_c)
  print_min_values(headers, min_a, min_b, min_c)
  print_moving_average(headers, sma_a, sma_b, sma_c)
  return True
