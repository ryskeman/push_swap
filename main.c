/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernafer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:59:10 by fernando          #+#    #+#             */
/*   Updated: 2025/06/30 15:59:46 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // Temporal para printf en depuración, puedes eliminarlo después.

// --- Función auxiliar para imprimir un stack (solo para depuración) ---
// Puedes mover esto a stack_utils.c si lo usas con frecuencia.
void print_stack(t_node *stack, const char *name)
{
    printf("--- Stack %s (top to bottom) ---\n", name);
    if (!stack)
    {
        printf("Stack is empty.\n");
        return;
    }
    while (stack)
    {
        printf("%d (index: %d)\n", stack->value, stack->index);
        stack = stack->next;
    }
    printf("---------------------------\n");
}

// --- Función para parsear los argumentos y llenar el stack 'a' ---
// (Esta función la tenías antes en main.c, la mantenemos aquí para simplicidad de la prueba)
void    parse_and_fill_stack_a(t_push_swap *data, char **argv)
{
    int i;
    t_node *new;

    i = 1; // Empezamos desde el primer argumento numérico
    // Inicializa los stacks y sus tamaños/tails a NULL o 0
    data->stack_a = NULL;
    data->stack_b = NULL;
    data->size_a = 0;
    data->size_b = 0;
    data->tail_a = NULL; // Inicializar tail_a
    data->tail_b = NULL; // Inicializar tail_b

    // Recorre los argumentos y añade los nodos al frente del stack_a.
    // Esto significa que argv[1] será el primer elemento (top) del stack.
    while (argv[i])
    {
        new = new_node((int)ft_atol(argv[i])); // Crea un nuevo nodo
        // Usa la add_front que actualiza el tail
        add_front(&(data->stack_a), &(data->tail_a), new);
        data->size_a++;
        i++;
    }
}


int main(int argc, char **argv)
{
    t_push_swap data; // Declara la estructura que contendrá tus stacks

    // 1. Manejo de errores inicial: valida los argumentos
    // Prueba: `./push_swap 1 2 3 4 5` -> OK
    // Prueba: `./push_swap 1 2 3 2 5` -> Error (duplicado)
    // Prueba: `./push_swap 1 2 abc 4 5` -> Error (no número)
    // Prueba: `./push_swap 2147483648` -> Error (fuera de rango INT)
    // Prueba: `./push_swap` -> Salida exitosa sin imprimir nada
    check_arguments(argc, argv);

    // Si argc < 2, check_arguments ya habrá salido. Así que siempre tendremos args válidos aquí.
    printf("\n--- Args OK. Building Stack A ---\n");

    // 2. Parsear los argumentos y construir el stack 'a'
    parse_and_fill_stack_a(&data, argv);

    // --- FASE DE PRUEBAS DE OPERACIONES ---
    printf("\n--- Initial State ---\n");
    print_stack(data.stack_a, "A");
    print_stack(data.stack_b, "B");
    printf("Sizes: A=%d, B=%d\n", data.size_a, data.size_b);
    if (data.tail_a)
        printf("Tail A: %d\n", data.tail_a->value);
    if (data.tail_b)
        printf("Tail B: %d\n", data.tail_b->value);


    // --- Prueba sa (swap a) ---
    printf("\n--- Performing sa ---\n");
    sa(&data);
    print_stack(data.stack_a, "A");
    print_stack(data.stack_b, "B");
    printf("Sizes: A=%d, B=%d\n", data.size_a, data.size_b);
    if (data.tail_a)
        printf("Tail A: %d\n", data.tail_a->value);

    // --- Prueba pb (push b) ---
    printf("\n--- Performing pb ---\n");
    pb(&data);
    print_stack(data.stack_a, "A");
    print_stack(data.stack_b, "B");
    printf("Sizes: A=%d, B=%d\n", data.size_a, data.size_b);
    if (data.tail_a)
        printf("Tail A: %d\n", data.tail_a->value);
    if (data.tail_b)
        printf("Tail B: %d\n", data.tail_b->value);


    // --- Prueba pa (push a) ---
    printf("\n--- Performing pa ---\n");
    pa(&data);
    print_stack(data.stack_a, "A");
    print_stack(data.stack_b, "B");
    printf("Sizes: A=%d, B=%d\n", data.size_a, data.size_b);
    if (data.tail_a)
        printf("Tail A: %d\n", data.tail_a->value);
    if (data.tail_b)
        printf("Tail B: %d\n", data.tail_b->value);

    // --- Prueba ra (rotate a) ---
    printf("\n--- Performing ra ---\n");
    ra(&data);
    print_stack(data.stack_a, "A");
    print_stack(data.stack_b, "B");
    printf("Sizes: A=%d, B=%d\n", data.size_a, data.size_b);
    if (data.tail_a)
        printf("Tail A: %d\n", data.tail_a->value);

    // --- Prueba rra (reverse rotate a) ---
    printf("\n--- Performing rra ---\n");
    rra(&data);
    print_stack(data.stack_a, "A");
    print_stack(data.stack_b, "B");
    printf("Sizes: A=%d, B=%d\n", data.size_a, data.size_b);
    if (data.tail_a)
        printf("Tail A: %d\n", data.tail_a->value);


    // --- PRUEBAS ADICIONALES (descomenta para probar) ---
    // printf("\n--- Performing ss ---\n");
    // ss(&data);
    // print_stack(data.stack_a, "A");
    // print_stack(data.stack_b, "B");

    // printf("\n--- Performing rr ---\n");
    // rr(&data);
    // print_stack(data.stack_a, "A");
    // print_stack(data.stack_b, "B");

    // printf("\n--- Performing rrr ---\n");
    // rrr(&data);
    // print_stack(data.stack_a, "A");
    // print_stack(data.stack_b, "B");


    // 3. Liberar la memoria al final del programa
    // Es CRÍTICO liberar la memoria de ambos stacks, incluso si están vacíos.
    printf("\n--- Freeing memory ---\n");
    free_stack(&(data.stack_a));
    free_stack(&(data.stack_b)); // Liberar stack B también

    printf("Program finished successfully.\n");
    return (0);
}
