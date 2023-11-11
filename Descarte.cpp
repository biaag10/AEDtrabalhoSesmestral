Carta descarte(Pilha *pilha, int valor){
	if (pilha->topo < 7){
		pilha->carta[++(pilha->topo)].carta = valor;
	}else{
		int tamanho = 7;
		Carta deck[52];
		deck[52]= embaralhar Cartas(pilha, tamanho);
		
		return deck;
	}
}