import subprocess, json

def executar_lista(args):
    resultado = subprocess.run(['./app_lista'] + args, capture_output=True, text=True)
    return json.loads(resultado.stdout)

# Inserir valores na lista via API
dados = executar_lista(['10', '20', '30'])
print(dados)
