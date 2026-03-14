package main

import (
	"fmt"
)

func main() {
	var tanyawaktu int

	fmt.Print("Masukan waktu : ")
	fmt.Scanf("%d", &tanyawaktu)

	if tanyawaktu < 1 || tanyawaktu > 24 {
		fmt.Println("Wrong Format!")
	} else if tanyawaktu < 10 {
		fmt.Println("Good morning.")
	} else if tanyawaktu < 12 {
		fmt.Println("Good morning.")
	} else if tanyawaktu < 15 {
		fmt.Println("Good day.")
	} else if tanyawaktu < 18 {
		fmt.Println("Good evening.")
	} else {
		fmt.Println("Good Night")
	}
}