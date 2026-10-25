PrimeCheck Enterprise

Sistema profesional de validación y análisis de números primos

"Lenguaje" (https://img.shields.io/badge/Lenguaje-C-blue)
"Estándar" (https://img.shields.io/badge/Estándar-C11-orange)
"Versión" (https://img.shields.io/badge/Versión-1.0.0-green)

Descripción del proyecto

PrimeCheck Enterprise es una aplicación de consola desarrollada en lenguaje C para la validación y el análisis de números primos.

El sistema utiliza un algoritmo optimizado para determinar si un número es primo, compuesto o no pertenece a ninguna de estas categorías. También permite analizar múltiples números en una sola sesión y consultar los divisores de un número.

El proyecto está diseñado para demostrar conocimientos de programación estructurada, diseño de algoritmos, validación de datos, manejo de errores y desarrollo de aplicaciones de consola.

Funcionalidades principales

- Validación de números primos: determina si un número es primo o compuesto.
- Algoritmo optimizado: comprueba posibles divisores hasta la raíz cuadrada del número.
- Análisis por lotes: permite evaluar múltiples números en una sola ejecución.
- Análisis de divisores: identifica los divisores de un número dentro de un rango establecido.
- Validación de entradas: detecta valores inválidos y entradas que no corresponden a números enteros.
- Menú interactivo: facilita el acceso a las distintas funciones.
- Manejo de errores: controla entradas incorrectas y opciones no reconocidas.
- Resultados organizados: presenta los resultados mediante informes en consola.

Tecnologías utilizadas

- Lenguaje de programación C.
- Estándar C11.
- Compilador GCC.
- Visual Studio Code.
- Git y GitHub para el control de versiones.

Requisitos

Para ejecutar el proyecto necesitas:

- Un compilador compatible con C11, como GCC.
- Una terminal o consola de comandos.
- Windows, Linux u otro sistema operativo compatible.

Instalación y ejecución

1. Clonar el repositorio

Sustituye "TU_USUARIO" por tu nombre de usuario de GitHub.

git clone https://github.com/TU_USUARIO/PrimeCheck-Enterprise.git

2. Entrar en la carpeta del proyecto

cd PrimeCheck-Enterprise

3. Compilar el programa

gcc -std=c11 -Wall -Wextra -Wpedantic -O2 PrimeCheck.c -o PrimeCheck.exe

4. Ejecutar la aplicación

En PowerShell:

.\PrimeCheck.exe

Opciones del sistema

Opción| Función
1| Analizar un número
2| Analizar varios números
3| Mostrar los divisores de un número
0| Salir de la aplicación

Ejemplo de funcionamiento

========================================
       PrimeCheck Enterprise
                Version 1.0.0
========================================
1. Analyze a number
2. Batch analysis
3. Display divisors
0. Exit
========================================
Select an option: 1

Enter an integer: 97

========================================
           ANALYSIS REPORT
========================================
Input number: 97
Classification: PRIME
========================================

Funcionamiento del algoritmo

El algoritmo de validación aplica las siguientes reglas:

1. Los números menores que 2 no son primos.
2. El número 2 es primo.
3. Los números pares mayores que 2 no son primos.
4. Para los números impares, se prueban posibles divisores impares hasta determinar si existe alguno que divida exactamente al número.

La comprobación utiliza una condición que evita multiplicaciones innecesarias y reduce el riesgo de desbordamiento aritmético.

Complejidad algorítmica

- Tiempo: O(√n) en el peor caso.
- Espacio auxiliar: O(1) para la función de validación.

Casos de prueba recomendados

Entrada| Resultado esperado
2| Primo
3| Primo
4| Compuesto
17| Primo
97| Primo
1| No primo
0| No primo
-7| No primo
Texto no numérico| Error de entrada

Mejoras futuras

- Implementación de pruebas automatizadas.
- Separación del código en archivos ".c" y ".h".
- Integración continua con GitHub Actions.
- Registro estructurado de errores.
- Pruebas de rendimiento con números grandes.
- Exportación de resultados a archivos.
- Incorporación de otros algoritmos matemáticos.

Licencia

Este proyecto puede distribuirse bajo la licencia MIT si se incluye el archivo correspondiente y se cumplen sus condiciones.

Autor

Proyecto de portafolio enfocado en programación en C, diseño de algoritmos, validación de datos y desarrollo de aplicaciones de consola.
