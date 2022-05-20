#include "sway/config.h"
#include "sway/commands.h"
#include "sway/input/cursor.h"

struct cmd_results *input_cmd_scroll_button_lock(int argc, char **argv) {
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "scroll_button_lock", EXPECTED_AT_LEAST, 1))) {
		return error;
	}
	struct input_config *ic = config->handler_context.input_config;
	if (!ic) {
		return cmd_results_new(CMD_FAILURE, "No input device defined.");
	}

	if (strcmp(*argv, "disable") == 0) {
		ic->scroll_button_lock = 0;
		return cmd_results_new(CMD_SUCCESS, NULL);
	}

	ic->scroll_button_lock = LIBINPUT_CONFIG_SCROLL_BUTTON_LOCK_ENABLED;

	return cmd_results_new(CMD_SUCCESS, NULL);
}
