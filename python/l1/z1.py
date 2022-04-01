from decimal import *

getcontext().prec = 25

def vat_faktura(lista):
    suma_cen=sum(lista)
    vat=0.23*suma_cen
    print(vat)
    return vat

def vat_paragon(lista):
	lista_podatkow=[cena * 0.23 for cena in lista]
	vat = sum(lista_podatkow)
	print(vat)
	return vat
	
	
	
def decimal_vat_faktura(lista):
    sumprice=Decimal(0.0)
    for x in lista:
        sumprice=Decimal(sumprice)+Decimal(x)
    vat=Decimal(0.23)*Decimal(sumprice)
    print(vat)
    return vat

def decimal_vat_paragon(lista):
	vat=Decimal(0.0)
	for x in lista:
	    vat=Decimal(vat)+Decimal(x)*Decimal(0.23)
	print(vat)    
	return vat	
	

zakupy = [0.2, 0.5, 4.59, 6]
print(vat_faktura(zakupy) == vat_paragon(zakupy))
print(decimal_vat_faktura(zakupy) == decimal_vat_paragon(zakupy))

	