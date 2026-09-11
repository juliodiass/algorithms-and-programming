import os

restaurantes = [{"nome":"Ohashi", "categoria":"Japonesa", "ativo":False}, 
                {"nome":"Zé da Pizza", "categoria":"Italiana", "ativo":True},
                {"nome":"Burguer King", "categoria":"Fast Food", "ativo":True}]


def exibir_nome_app():
    #Exibe o nome estilizado do programa na tela
    print("""
    ░██████╗░█████╗░██████╗░░█████╗░██████╗░  ███████╗██╗░░██╗██████╗░██████╗░███████╗░██████╗░██████╗
    ██╔════╝██╔══██╗██╔══██╗██╔══██╗██╔══██╗  ██╔════╝╚██╗██╔╝██╔══██╗██╔══██╗██╔════╝██╔════╝██╔════╝
    ╚█████╗░███████║██████╦╝██║░░██║██████╔╝  █████╗░░░╚███╔╝░██████╔╝██████╔╝█████╗░░╚█████╗░╚█████╗░
    ░╚═══██╗██╔══██║██╔══██╗██║░░██║██╔══██╗  ██╔══╝░░░██╔██╗░██╔═══╝░██╔══██╗██╔══╝░░░╚═══██╗░╚═══██╗
    ██████╔╝██║░░██║██████╦╝╚█████╔╝██║░░██║  ███████╗██╔╝╚██╗██║░░░░░██║░░██║███████╗██████╔╝██████╔╝
    ╚═════╝░╚═╝░░╚═╝╚═════╝░░╚════╝░╚═╝░░╚═╝  ╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝╚══════╝╚═════╝░╚═════╝░\n""")
        
def exibir_menu():
    #Exibe o menu de opções do programa
    print("1. Cadastrar Restaurante")
    print("2. Listar Restaurante")
    print("3. Alternar Estado do Restaurante")
    print("4. Sair\n")

def finalizar_app():
    #Exibe mensagem de finalização do aplicativo.
    exibir_subtitulo("Você saiu do aplicativo.")

def voltar_menu():
    """
    Solicita ao usuário que pressione uma tecla para voltar ao menu principal.

    Output:
    - Retorna ao menu principal.
    """
    input("\nPressione uma tecla para voltar ao menu.")
    main()

def exibir_subtitulo(texto):
    #Exibe um subtítulo estilizado na tela, com linhas acima e abaixo do texto.
    os.system("cls")
    linha = "-" * len(texto)
    print(linha)
    print(texto)
    print(linha)
    print()

def opcao_invalida():
    """
    Exibe mensagem de opção inválida e retorna ao menu principal.

    Output:
    - Retorna ao menu principal.
    """
    print("Opção inválida. Por favor, escolha uma opção válida.\n")
    voltar_menu()

def cadastrar_restaurante():
    #Função responsável por cadastrar um novo restaurante no sistema.
    exibir_subtitulo("Cadastro de novos restaurantes")
    """
    Inputs:
    - Nome do restaurante
    - Categoria do restaurante

    Output:
    - Adiciona o restaurante à lista de restaurantes
    """
    nome_restaurante = input("Digite o nome do restaurante do qual deseja cadastrar: ")
    categoria = input(f"Digite a categoria do restaurante {nome_restaurante}: ")
    dados_restaurante = {"nome":nome_restaurante, 
                         "categoria":categoria,
                         "ativo":False}
    restaurantes.append(dados_restaurante)
    print(f"Restaurante {nome_restaurante} cadastrado com sucesso!\n")
    voltar_menu()

def listar_restaurantes():
    """
    Lista os restaurantes cadastrados no sistema, exibindo o nome, categoria e status (ativado/desativado) de cada um.

    Output:
    - Exibe a lista de restaurantes na tela.
    """
    exibir_subtitulo("Listando os restaurantes cadastrados")
    print(f"{'Nome do Restaurante:'.ljust(22)} | {'Categoria:'.ljust(20)} | {'Status:'}")
    for restaurante in restaurantes:
        nome_restaurante = restaurante["nome"]
        categoria = restaurante["categoria"]
        ativo = "Ativado" if restaurante["ativo"] else "Desativado"
        print(f". {nome_restaurante.ljust(20)} | {categoria.ljust(20)} | {ativo}")
    voltar_menu()

def alternar_estado_restaurante():
    """
    Altera o estado ativo/desativado de um restaurante 
    
    Outputs:
    - Exibe mensagem indicando o sucesso da operação
    """
    exibir_subtitulo("Ativando/Desativando restaurante")
    nome_restaurante = input("Digite o nome do restaurante que deseja ativar/desativar: ")
    restaurante_encontrado = False
    for restaurante in restaurantes:
        if nome_restaurante == restaurante["nome"]:
            restaurante_encontrado = True
            restaurante["ativo"] = not restaurante["ativo"]
            mensagem = f"O restaurante {nome_restaurante} foi ativado com sucesso!" if restaurante["ativo"] else f"O restaurante {nome_restaurante} foi desativado com sucesso!"
            print(mensagem)
    if not restaurante_encontrado:
        print(f"Restaurante {nome_restaurante} não encontrado.")

    voltar_menu()

def opcao_menu():
    """
    Solicita e executa a opção escolhida pelo usuário no menu principal.

    Outputs:
    - Executa a opção escolhida pelo usuário
    """
    try:
        opcao_escolhida = int(input("Escolha uma opção: "))
        if opcao_escolhida == 1:
            cadastrar_restaurante()
        elif opcao_escolhida == 2:
            listar_restaurantes()
        elif opcao_escolhida == 3:
            alternar_estado_restaurante()
        elif opcao_escolhida == 4:
            finalizar_app()
        else:
            opcao_invalida()
    except:
        opcao_invalida()
def main():
    #Função principal do aplicativo, responsável por iniciar o programa e exibir o menu de opções.
    os.system("cls")
    exibir_subtitulo("Iniciando o aplicativo.")
    exibir_nome_app()
    exibir_menu()
    opcao_menu()

if __name__ == "__main__":

    main()