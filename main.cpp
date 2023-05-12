#define POTENTIOMETER_PIN A0
#define POTENTIOMETER_VALUES_MAX_SIZE 10

void append_to_potentiometer_array();
void calc_mean_of_potentiometer_array();

int current_potentiometer_value = 0;
int previous_potentiometer_value = 0;
int potentiometer_values[POTENTIOMETER_VALUES_MAX_SIZE];
int potentiometer_values_length = 0;
int potentiometer_values_sum = 0;

void append_to_potentiometer_array() {
  	if (potentiometer_values_length < POTENTIOMETER_VALUES_MAX_SIZE) {
    	potentiometer_values[potentiometer_values_length] = current_potentiometer_value;
    	potentiometer_values_length++;

    	Serial.println("Novo valor adicionado em: 'potentiometer_values'");

    	return;
  	}

  	Serial.println("O vetor 'potentiometer_values' está com capacidade cheia");
}

void calc_mean_of_potentiometer_array() {
	if (potentiometer_values_length == POTENTIOMETER_VALUES_MAX_SIZE) {
    	for (int i = 0; i < POTENTIOMETER_VALUES_MAX_SIZE; i++) {
  			potentiometer_values_sum += potentiometer_values[i];
       	}

      	float potentiometer_values_mean = static_cast<float>(potentiometer_values_sum) / POTENTIOMETER_VALUES_MAX_SIZE;

    	Serial.print("O vetor da média entre os 10 valores inseridos é: ");
      	Serial.println(potentiometer_values_mean);
    }
}

void setup() {
  	Serial.begin(115200);

	pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  	current_potentiometer_value = analogRead(POTENTIOMETER_PIN);

	if (current_potentiometer_value != previous_potentiometer_value) {
		append_to_potentiometer_array();

    	previous_potentiometer_value = current_potentiometer_value;

      	calc_mean_of_potentiometer_array();
    }

    delay(200);
}
