function findOddNumber(array) {
  const countMap = {};

  for (let num of array) {
    countMap[num] = (countMap[num] || 0) + 1;
  }

  for (let num in countMap) {
    if (countMap[num] % 2 !== 0) {
      return parseInt(num);
    }
  }
}

// Examples:
console.log(findOddNumber([7])); // Output: 7
console.log(findOddNumber([0])); // Output: 0
console.log(findOddNumber([1, 1, 2])); // Output: 2
console.log(findOddNumber([0, 1, 0, 1, 0])); // Output: 0
console.log(findOddNumber([1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1])); // Output: 4
