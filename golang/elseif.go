package main

import (
	"fmt"
)

func main() {
	var tanyawaktu int
	var nama string

	fmt.Print("Masukan waktu : ")
	fmt.Scanf("%d", &tanyawaktu)
	
	fmt.Print("Masukan Nama : ")
	fmt.Scanf("%s", &nama)

	if tanyawaktu < 1 || tanyawaktu > 24 {
		fmt.Println("Format Salah!")
	} else if tanyawaktu < 10 {
		fmt.Printf("Good morning, %s!\n", nama)
	} else if tanyawaktu < 12 {
		fmt.Printf("Good morning, %s!\n", nama)
	} else if tanyawaktu < 15 {
		fmt.Printf("Good day, %s!\n", nama)
	} else if tanyawaktu < 18 {
		fmt.Printf("Good evening, %s!\n", nama)
	} else {
		fmt.Printf("Good Night, %s!\n", nama)
	}
}