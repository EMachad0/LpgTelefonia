from random import randint

vogal = ['a', 'e', 'i', 'o', 'u']
consoante = sorted(list({chr(i+97) for i in range(26)}-set(vogal)))

def geraString():
    frase = []
    palavras = randint(1, 3)
    for j in range(palavras):
        palavra = []
        letras = randint(4, 16)
        for k in range(letras):
            if k%2==0:
                palavra.append(consoante[randint(0, len(consoante)-1)])
            else:
                palavra.append(vogal[randint(0, len(vogal)-1)])

        # palavra[0] = palavra[0].upper();
        frase.append("".join(palavra))
    return " ".join(frase);

# 18 campos
def geraPessoa():
    li = [1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1]
    for i in range(len(li)):
        if li[i] == 1:
            li[i] = geraString()
        elif li[i] == 0:
            li[i] = randint(0, 1000000009)
    return li

quant = 10
for i in range(quant):
    p = geraPessoa()
    print(1)
    for j in p:
        print(j)
print(3)
