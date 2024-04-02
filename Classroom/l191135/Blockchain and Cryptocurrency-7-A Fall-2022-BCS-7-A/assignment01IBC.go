package main

import (
	"crypto/sha256"
	"fmt"
	"strings"
	"reflect"
)

type Block struct {
	transactions []string
	prevPointer  *Block
	prevHash     string
	currentHash  string
}

func main() {
	var x1 *Block = InsertBlock([]string{"My name is Abdul", "I'm a boy"}, nil)
	x1 = InsertBlock([]string{"My name is Anato", "I'm a boy"}, x1)
	x1 = InsertBlock([]string{"My name is Ali", "I'm a boy"}, x1)
	x1 = InsertBlock([]string{"My name is Sara", "I'm a girl"}, x1)
	x1 = InsertBlock([]string{"My name is Nini", "I'm a girl"}, x1)
	ListBlocks(x1)
}

func VerifyChain(chainHead *Block) {
	//check whether "Block chain is compromised" or "Block chain is unchanged"
	if chainHead != nil {
		if chainHead.prevPointer != nil {
			if chainHead.prevHash != CalculateHash(chainHead.prevPointer) {
				fmt.Println("Block chain is compromised.")
			}
		}
	}
}

func InsertBlock(transactionsToInsert []string, chainHead *Block) *Block {
	//insert new block and return head pointer
	var x1 Block
	x1.transactions = transactionsToInsert
	x1.prevPointer = chainHead
	if chainHead != nil {
		x1.prevHash = chainHead.currentHash
	}
	x1.currentHash = CalculateHash(&x1)
	return &x1
}

func CalculateHash(inputBlock *Block) string {
	var input string
	input = strings.Join(inputBlock.transactions, "")
	input = input + inputBlock.prevHash
	hash := sha256.Sum256([]byte(input))
	return string(hash[:])
}

func ChangeBlock(oldTrans []string, newTrans []string, chainHead *Block) {
	if chainHead != nil {
		if reflect.DeepEqual(chainHead.transactions, oldTrans) == true {
			chainHead.transactions = newTrans
		} else if chainHead.prevPointer != nil {
			ChangeBlock(oldTrans, newTrans, chainHead.prevPointer)
		}
	}
}

func ListBlocks(chainHead *Block) {
	//dispaly the data(transaction) inside all blocks
	if chainHead != nil {
		fmt.Printf("\tBlock %v:", &chainHead)
		fmt.Printf("\n\tprevHash: ", chainHead.prevHash)
		fmt.Printf("\n\tcurrentHash: ", chainHead.currentHash)
		fmt.Println("\n\tTransactions:")
		for i, transaction := range chainHead.transactions {
			fmt.Printf("\t\t%v:%q\n", i, transaction)
		}
		fmt.Println("\n")
		if chainHead.prevPointer != nil {
			ListBlocks(chainHead.prevPointer)
		}
	}
}
