import subprocess, json

def executar_lista(args):
    resultado = subprocess.run(['./app_lista'] + args, capture_output=True, text=True)
    return json.loads(resultado.stdout)

def executar_pilha(args):
    resultado = subprocess.run(['./app_pilha'] +args, capture_output=True, text=True)
    return json.loads(resultado.stdout)

# iInserir valores via API e vê o resultado
dados = executar_lista(['10', '20', '30'])
print("Lista:" +str(dados))
dados = executar_pilha(['10', '20', '30'])
print("Pilha: " +str(dados))

