const find3Sum = function(arr) {
  let i = 0;
  let result = [];

  arr.sort((a, b) => a - b);

  while (i < arr.length - 2) {
    let startIdx = i + 1;
    let endIdx = arr.length - 1;

    // Because we sorted, the first number (arr[i]) can not be positive
    if (arr[i] > 0) {
      break;
    }

    while (startIdx < endIdx) {
      if (arr[i] + arr[startIdx] + arr[endIdx] === 0) {
        result.push([arr[i], arr[startIdx], arr[endIdx]]);

        // Moving the pointer
        while (arr[startIdx] === arr[startIdx + 1]) {
          startIdx++;
        }

        while (arr[endIdx] === arr[endIdx - 1]) {
          endIdx--;
        }

        startIdx++;
        endIdx--;
      } else if (arr[i] + arr[startIdx] + arr[endIdx] < 0) {
        startIdx++;
      } else {
        endIdx--;
      }
    }

    // Preventing duplicate
    while (i < arr.length - 3 && arr[i] === arr[i + 1]) {
      i++;
    }

    i++;
  }

  return result;
}
