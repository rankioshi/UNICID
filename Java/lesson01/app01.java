package aula2202;

import java.util.Scanner;
public class App2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Digite o nome ");
		String nome = sc.nextLine();
		System.out.println("Nome "+nome);
		
		System.out.println("Digite a idade");
		int idade = sc.nextInt();
		System.out.println("Idade "+idade);
		
		System.out.println("Digite o salario");
		int salario = sc.nextInt();
		System.out.println("Salario: "+salario);
		
		sc.close();
	}

}
