import os

restaurantes = ["Sabor caseiro", "Cheiro e sabor"]

def exibir_nome_app():
    print("""
    ░██████╗░█████╗░██████╗░░█████╗░██████╗░  ███████╗██╗░░██╗██████╗░██████╗░███████╗░██████╗░██████╗
    ██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔════╝╚██╗██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝
    ╚█████╗░███████║██████╦╝██║░░██║██████╔╝  █████╗░░░╚███╔╝░██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░
    ░╚═══██╗██╔══██║██╔══██╗██║░░██║██╔══██╗  ██╔══╝░░░██╔██╗░██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗
    ██████╔╝██║░░██║██████╦╝╚█████╔╝██║░░██║  ███████╗██╔╝╚██╗██║░░░░░██║░░██║███████╗██████╔╝██████╔╝
    ╚═════╝░╚═╝░░╚═╝╚═════╝░░╚════╝░╚═╝░░╚═╝  ╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░\n""")
        
def exibir_menu():
    print("1. Cadastrar Restaurante")
    print("2. Listar Restaurante")
    print("3. Ativar Restaurante")
    print("4. Sair\n")

def finalizar_app():
    os.system("cls")
    print("Você saiu do aplicativo.\n")

def opcao_invalida():
    print("Opção inválida. Por favor, escolha uma opção válida.\n")
    input("Pressione uma tecla para voltar ao menu.")
    main()

def cadastrar_restaurante():
    os.system("cls")
    print("Cadastro de novos restaurantes\n")
    nome_restaurante = input("Digite o nome do restaurante do qual deseja cadastrar: ")
    restaurantes.append(nome_restaurante)
    print(f"Restaurante {nome_restaurante} cadastrado com sucesso!\n")
    input("Pressione uma tecla para voltar ao menu principal.")
    main()

def listar_restaurantes():
    os.system("cls")
    print("Listando os restaurantes cadastrados\n")
    for restaurante in restaurantes:
        print(f". {restaurante}")
    input("\nPressione uma tecla para voltar ao menu principal.")
    main()

def opcao_menu():
    try:
        opcao_escolhida = int(input("Escolha uma opção: "))
        if opcao_escolhida == 1:
            cadastrar_restaurante()
        elif opcao_escolhida == 2:
            listar_restaurantes()
        elif opcao_escolhida == 3:
            print("Você escolheu a opção 3: Ativar Restaurante")
        elif opcao_escolhida == 4:
            finalizar_app()
        else:
            opcao_invalida()
    except:
        opcao_invalida()
def main():
    os.system("cls")
    exibir_nome_app()
    exibir_menu()
    opcao_menu()

if __name__ == "__main__":

    main()