func divisorGame(N int) bool {
  result := make([]bool, N+1)

  result[0] = false
  result[1] = false

  if N > 1 {
    result[2] = true
  }

  if N > 2 {
    result[3] = false
  }

  for i := 4; i <= N; i++ {
    result[i] = false

    for j := 1; j < i; j++ {
      if i % j  == 0 && result[j] == true {
        result[i] = true

        break
      }
    }
  }

  return result[N]
}
