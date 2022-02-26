# EjerciciosEzequielA

## Instrucciones para Ejecutar e1 (Linux)
Descargue el repositorio,descomprima y en una terminal navegue hasta la ruta donde se encuentra el archivo makefile. Ejecute las reglas compile y execute como se muestra a continuación:

```bash
cd e1/utils
make compile
make execute
```
*Nota: El archivo generado es un \*.txt que se ubica en el directorio utils junto al makefile.*

## Instrucciones para Ejecutar e2 (Linux)
Descargue el repositorio,descomprima y en una terminal navegue hasta la ruta donde se encuentra el archivo makefile. Ejecute las reglas compile y execute como se muestra a continuación:

```bash
cd e2/utils
make compile
make execute
```
*Nota: Los archivos generados son \*.dat que se ubican en el directorio utils junto al makefile.*

### Registros ranges.dat y cards.dat
Los registros fueron cargados como se muestra a continuación:

* ranges.dat:

```bash
		RangeLow 	RangeHigh 	len id
		00000000 	11111111	13	0
		11110000	22221111	14	1
		22220000	33331111	15	2
```
* cards.dat:

```bash
		label           id  	    
		tarjeta_0        0 		
		tarjeta_1        1 		
		tarjeta_2        2  		
```

Así es que unos ejemplos de números de tarjetas pueden ser:

```bash
		id  	numero
		0 		1111111112345
 		1 		22211111123456
		2 		222200001234567
```
---

Se agradecen cualquier tipo de sugerencias a ealegremendoza@gmail.com

*Alegre Mendoza Ezequiel.*