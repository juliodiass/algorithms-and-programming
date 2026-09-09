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
    exibir_subtitulo("Você saiu do aplicativo.")

def voltar_menu():
    input("\nPressione uma tecla para voltar ao menu.")
    main()

def exibir_subtitulo(texto):
    os.system("cls")
    print(texto)
    print()

def opcao_invalida():
    print("Opção inválida. Por favor, escolha uma opção válida.\n")
    voltar_menu()

def cadastrar_restaurante():
    exibir_subtitulo("Cadastro de novos restaurante")
    nome_restaurante = input("Digite o nome do restaurante do qual deseja cadastrar:")
    restaurantes.append(nome_restaurante)
    print(f"Restaurante {nome_restaurante} cadastrado com sucesso!\n")
    voltar_menu()

def listar_restaurantes():
    exibir_subtitulo("Listando os restaurantes cadastrados")
    for restaurante in restaurantes:
        print(f". {restaurante}")
    voltar_menu()

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
    exibir_subtitulo("Iniciando o aplicativo...")
    exibir_nome_app()
    exibir_menu()
    opcao_menu()

if __name__ == "__main__":

    main()