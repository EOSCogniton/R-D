/*
 * bsp_counter.c
 *
 * Created: 03/06/2026 22:15:12
 *  Author: maxbo
 */ 

#include <atmel_start.h>

// Le mot-clé "volatile" est OBLIGATOIRE ici.
// Il dit au compilateur : "Attention, cette variable est modifiée en tâche de fond par une interruption !"
volatile uint32_t system_ms = 0;

// La fonction qui sera appelée automatiquement par le hardware toutes les 1 ms
static void timer_1ms_callback(const struct timer_task *const timer_task)
{
	system_ms++; // On ajoute 1 milliseconde
}

// Fonction publique pour que ton code puisse "lire l'heure"
uint32_t get_system_ms(void)
{
	return system_ms;
}

// Initialisation (à appeler dans ton main avant le while(1))
void bsp_timer_init(void)
{
	static struct timer_task task_1ms;
	
	// On configure la tâche pour qu'elle s'exécute toutes les 1 unité du timer (donc 1ms)
	task_1ms.interval = 1;
	task_1ms.cb       = timer_1ms_callback;
	task_1ms.mode     = TIMER_TASK_REPEAT;

	timer_add_task(&TIMER_0, &task_1ms);
	timer_start(&TIMER_0);
}