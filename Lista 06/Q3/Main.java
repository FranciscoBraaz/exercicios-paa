package kmpMatriz;



public class Main {

	public static void main(String[] args) {
		String expressao[]= {
	            "LMPORCOBGCA",
	            "EMYKVACAGAL",
	            "BMACACOMALP",
	            "RLLMATNGAMA",
	            "ELEPATNMACT",
	            "OURSTIFOCCO",
	            "MRUYYTXZEBR",
	            "NAUTICHZATC",
	            "PAMELHEUSAA",
	            "YLULHABIUSL",
	            "BCVABELHABA"
	    };
		
		String padrao[] = {"LEBRE", "MACACO", "ORCA", "PATO", "PORCO", "VACA"};
		busca(expressao, padrao);
	}
	
	static void computaNext(char padrao[], int tam, int next[]) {
		next[0] = -1;
		next[1] = 0;
		int j = 0;
		for(int i = 2; i < tam; i++) {
			j = next[i-1] + 1;
			while((j > 0) && (padrao[i-1] != padrao[j-1]) ) {
				j = next[j-1] + 1;
			}
			next[i] = j;
		}
	}
	
	static int kmp(char expressao[], int n, String padrao, int m, int next[]) {
		char padraoChar[] = padrao.toCharArray();
		int i = 0;
		int j = 0;
		int index = -1;
		while(index == -1 && i<=n) {
			if(expressao[i] == padraoChar[j]) {
				i = i + 1;
				j = j + 1;
			} else {
				j = next[j];
				if(j == -1) {
					j = 0;
					i = i + 1;
				}
			}
			if(j == m) {
				index = i-(m);
			}
		}
		
		return index;
	}
	
	static void iniciaKMP(String matriz[], String padrao, int tamPadrao) {
		char padraoChar[] = padrao.toCharArray();
		int next[] = new int[tamPadrao];
	    char arrayCol[] = new char[11];
	    computaNext(padraoChar, tamPadrao, next);
	    int posPrimeira[] = new int[2];
	    int posUltima[] = new int[2];
	    int encontrouLinha = 0;
	    int encontrouColuna = 0;
	    for(int i=0; i<11; i++) {
	    	char matrizChar[] = matriz[i].toCharArray();
	        int elementoLinha = kmp(matrizChar, 10, padrao, tamPadrao, next);
	        if(elementoLinha != -1) {
	            encontrouLinha = 1;
	            posPrimeira[0] = i;
	            posPrimeira[1] = elementoLinha;
	            posUltima[0] = i;
	            posUltima[1] = elementoLinha +  (tamPadrao);
	        }
	        
	        for(int j=0; j<11; j++) {
	            arrayCol[j] = matriz[j].charAt(i);
	        }

	        int elementoColuna = kmp(arrayCol, 10, padrao, tamPadrao, next);
	        if(elementoColuna != -1) {
	            encontrouColuna = 1;
	            posPrimeira[1] = i;
	            posPrimeira[0] = elementoColuna;
	            posUltima[1] = i;
	            posUltima[0] = elementoColuna +  (tamPadrao);
	        }
	    }

	    if(encontrouColuna != 0 || encontrouLinha != 0) {
	    	System.out.print("(");
	        System.out.print(padrao + "," + "(");
	        for(int i =0; i<2; i++) {
	        	if(i==0) {
	        		System.out.print(posPrimeira[i] + ",") ;
	        	} else {
	        		System.out.print(posPrimeira[i]) ;
	        	}
	            
	        }
	        System.out.print("),");
	        System.out.print("(");
	        for(int i =0; i<2; i++) {
	        	if(i==0) {
	        		System.out.print(posUltima[i] + ",") ;
	        	} else {
	        		System.out.print(posUltima[i]) ;
	        	}
	            
	        }
	        System.out.print(")");
	        System.out.print("),");
	    }
	}
	
	static void busca(String expressao[], String padrao[]) {
		for(int i=0; i<padrao.length; i++) {
			iniciaKMP(expressao, padrao[i], padrao[i].length()-1);
		}
	}
	

}
