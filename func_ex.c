#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int obtenerCadena(char *cadena, int longitud)
{
	int retorno = -1;
	if (cadena != NULL && longitud > 0 && fgets(cadena, longitud, stdin) == cadena)
	{
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n')
		{
			cadena[strlen(cadena) - 1] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}
int obtenerInt(int *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (obtenerCadena(buffer, sizeof(buffer)) == 0 && comprobacionNumero(buffer))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	}
	return retorno;
}
void codigoVuelo_p(char codigoVuelo[10], char* mensaje)
{
	printf(mensaje);
	fflush(stdin);
	gets(codigoVuelo);
}
int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo)
{
	int bufferInt;
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (obtenerInt(&bufferInt) == 0)
		{
			if (bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
	}
	return retorno;
}



int utn_getFloat(char *pResultado, char *mensaje, char *mensajeError)
{
	char bufferFloat[64];
	int retorno = -1;

	while (retorno != 0)
	{
		printf("%s", mensaje);
		if (obtenerFloat(bufferFloat) == 0)
		{
			strcpy(pResultado,bufferFloat);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}

int comprobacionNumero(char *cadena)
{
	int i = 0;
	int retorno = -1;
	if (cadena != NULL && strlen(cadena) > 0)
	{
		while (cadena[i] != '\0')
		{
			if (isalpha(cadena[i]) != 0)
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
void aMayus(char* cadena)
{
	strlwr(cadena);

	cadena[0] = toupper(cadena[0]);

	for(int i = 0; i < strlen(cadena); i++)
	{
		if (cadena[i] == ' ')
		{
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}
}

int obtenerNombre(char* cadena, char* mensaje, char* mensajeError)
{
	int retorno = -1;

	while(retorno != 0)
	{
		printf(mensaje);
		fflush(stdin);
		gets(cadena);
		for (int i = 0; i < strlen(cadena); i++)
		{
			if(isalpha(cadena[i]) == 0 && isspace(cadena[i]) == 0 && cadena[i] != '�')
			{
				retorno = -1;
				printf(mensajeError);
				break;
			}
			retorno = 0;
		}
	}

	aMayus(cadena);

	return retorno;
}

int obtenerFloat(char *pResultado)
{
	int retorno = -1;
	char buffer[64];

	if (pResultado != NULL)
	{
		if (obtenerCadena(buffer, sizeof(buffer)) == 0 && comprobacionNumero(buffer))
		{
			strcpy(pResultado,buffer);
			retorno = 0;
		}
	}
	return retorno;
}
