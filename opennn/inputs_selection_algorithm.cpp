/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.artelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   I N P U T S   S E L E C T I O N   A L G O R I T H M   C L A S S                                            */
/*                                                                                                              */
/*   Fernando Gomez                                                                                             */
/*   Artelnics - Making intelligent use of data                                                                 */
/*   fernandogomez@artelnics.com                                                                                */
/*                                                                                                              */
/****************************************************************************************************************/


// OpenNN includes

#include "inputs_selection_algorithm.h"

namespace OpenNN {

// DEFAULT CONSTRUCTOR

/// Default constructor.

InputsSelectionAlgorithm::InputsSelectionAlgorithm(void)
    : training_strategy_pointer(NULL)
{
    set_default();
}


// TRAINING STRATEGY CONSTRUCTOR

/// Training strategy constructor.
/// @param new_training_strategy_pointer Pointer to a trainig strategy object.

InputsSelectionAlgorithm::InputsSelectionAlgorithm(TrainingStrategy* new_training_strategy_pointer)
    : training_strategy_pointer(new_training_strategy_pointer)
{
    set_default();
}


// FILE CONSTRUCTOR

/// File constructor.
/// @param file_name Name of XML inputs selection file.

InputsSelectionAlgorithm::InputsSelectionAlgorithm(const std::string&)
    : training_strategy_pointer(NULL)
{
}


// XML CONSTRUCTOR

/// XML constructor.
/// @param inputs_selection_document Pointer to a TinyXML document containing the inputs selection algorithm data.

InputsSelectionAlgorithm::InputsSelectionAlgorithm(const tinyxml2::XMLDocument&)
    : training_strategy_pointer(NULL)
{
}


// DESTRUCTOR

/// Destructor.

InputsSelectionAlgorithm::~InputsSelectionAlgorithm(void)
{
}


// METHODS

// const bool& get_regression(void) const method

/// Returns whether the problem is a regression.

const bool& InputsSelectionAlgorithm::get_regression(void) const
{
    return regression;
}

// TrainingStrategy* get_training_strategy_pointer(void) const method

/// Returns a pointer to the training strategy object.

TrainingStrategy* InputsSelectionAlgorithm::get_training_strategy_pointer(void) const
{
#ifdef __OPENNN_DEBUG__

    if(!training_strategy_pointer)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "DataSet* get_training_strategy_pointer(void) const method.\n"
               << "Training strategy pointer is NULL.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    return(training_strategy_pointer);
}

// bool has_training_strategy(void) const method

/// Returns true if this inputs selection algorithm has a training strategy associated, and false otherwise.

bool InputsSelectionAlgorithm::has_training_strategy(void) const
{
    if(training_strategy_pointer)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

// const size_t& get_trials_number(void) const method

/// Returns the number of trials for each network architecture.

const size_t& InputsSelectionAlgorithm::get_trials_number(void) const
{
    return(trials_number);
}

// const bool& get_reserve_parameters_data(void) const method

/// Returns true if the neural network parameters are to be reserved, and false otherwise.

const bool& InputsSelectionAlgorithm::get_reserve_parameters_data(void) const
{
    return(reserve_parameters_data);
}


// const bool& get_reserve_performance_data(void) const method

/// Returns true if the performance functional performances are to be reserved, and false otherwise.

const bool& InputsSelectionAlgorithm::get_reserve_performance_data(void) const
{
    return(reserve_performance_data);
}


// const bool& get_reserve_generalization_performance_data(void) const method

/// Returns true if the selection performances are to be reserved, and false otherwise.

const bool& InputsSelectionAlgorithm::get_reserve_generalization_performance_data(void) const
{
    return(reserve_generalization_performance_data);
}


// const bool& get_reserve_minimal_parameters(void) const method

/// Returns true if the parameters vector of the neural network with minimum selection performance is to be reserved, and false otherwise.

const bool& InputsSelectionAlgorithm::get_reserve_minimal_parameters(void) const
{
    return(reserve_minimal_parameters);
}

// const PerformanceCalculationMethod& get_performance_calculation_method(void) const method

/// Returns the method for the calculation of the performance and the selection performance.

const InputsSelectionAlgorithm::PerformanceCalculationMethod& InputsSelectionAlgorithm::get_performance_calculation_method(void) const
{
    return(performance_calculation_method);
}

// const bool& get_display(void) const method

/// Returns true if messages from this class can be displayed on the screen,
/// or false if messages from this class can't be displayed on the screen.

const bool& InputsSelectionAlgorithm::get_display(void) const
{
    return(display);
}

// const double& get_selection_performance_goal(void) const method

/// Returns the goal for the selection performance in the inputs selection algorithm.

const double& InputsSelectionAlgorithm::get_selection_performance_goal(void) const
{
    return(selection_performance_goal);
}


// const size_t& get_maximum_iterations_number(void) const method

/// Returns the maximum number of iterations in the inputs selection algorithm.

const size_t& InputsSelectionAlgorithm::get_maximum_iterations_number(void) const
{
    return(maximum_iterations_number);
}


// const double& get_maximum_time(void) const method

/// Returns the maximum time in the inputs selection algorithm.

const double& InputsSelectionAlgorithm::get_maximum_time(void) const
{
    return(maximum_time);
}

// const double& get_maximum_correlation(void) const method

/// Return the maximum correlation for the algorithm.

const double& InputsSelectionAlgorithm::get_maximum_correlation(void) const
{
    return(maximum_correlation);
}

// const double& get_minimum_correlation(void) const method

/// Return the minimum correlation for the algorithm.

const double& InputsSelectionAlgorithm::get_minimum_correlation(void) const
{
    return(minimum_correlation);
}

// const double& get_tolerance(void) const method

/// Return the tolerance of error for the algorithm.

const double& InputsSelectionAlgorithm::get_tolerance(void) const
{
    return(tolerance);
}

// std::string write_performance_calculation_method(void) const method

/// Return a string with the performance calculation method of this inputs selection algorithm.

std::string InputsSelectionAlgorithm::write_performance_calculation_method(void) const
{
    switch (performance_calculation_method)
    {
    case Maximum:
    {
        return ("Maximum");
    }
    case Minimum:
    {
        return ("Minimum");
    }
    case Mean:
    {
        return ("Mean");
    }
    default:
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "std::string write_performance_calculation_method(void) const method.\n"
               << "Unknown performance calculation method.\n";

        throw std::logic_error(buffer.str());

        break;
    }
    }
}

// void set_regression(const bool&) method

/// Sets a new regression value.
/// If it is set to true the problem will be taken as a function regression;
/// if it is set to false the problem will be taken as a pattern recognition.
/// @param new_regression Regression value.

void InputsSelectionAlgorithm::set_regression(const bool& new_regression)
{
    regression = new_regression;
}



// void set_training_strategy_pointer(TrainingStrategy*) method

/// Sets a new training strategy pointer.
/// @param new_training_strategy_pointer Pointer to a training strategy object.

void InputsSelectionAlgorithm::set_training_strategy_pointer(TrainingStrategy* new_training_strategy_pointer)
{
    training_strategy_pointer = new_training_strategy_pointer;
}


// void set_default(void) method

/// Sets the members of the inputs selection object to their default values.

void InputsSelectionAlgorithm::set_default(void)
{

    // MEMBERS


    trials_number = 1;

    // inputs selection results

    reserve_parameters_data = true;
    reserve_performance_data = true;
    reserve_generalization_performance_data = true;
    reserve_minimal_parameters = true;

    performance_calculation_method = Minimum;

    display = true;

    // STOPPING CRITERIA

    selection_performance_goal = 0.0;

    maximum_iterations_number = 1000;

    maximum_correlation = 1e20;
    minimum_correlation = 0;

    maximum_time = 10000.0;

    tolerance = 1.0e-3;

}


// void set_trials_number(const size_t&) method

/// Sets the number of times that each different neural network is to be trained.
/// @param new_trials_number Number of trials for each set of parameters.

void InputsSelectionAlgorithm::set_trials_number(const size_t& new_trials_number)
{
#ifdef __OPENNN_DEBUG__

    if(new_trials_number <= 0)
    {
        std::ostringstream buffer;
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void set_trials_number(const size_t&) method.\n"
               << "Number of assays must be greater than 0.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    trials_number = new_trials_number;
}

// void set_reserve_parameters_data(const bool&) method

/// Sets the reserve flag for the parameters data.
/// @param new_reserve_parameters_data Flag value.

void InputsSelectionAlgorithm::set_reserve_parameters_data(const bool& new_reserve_parameters_data)
{
    reserve_parameters_data = new_reserve_parameters_data;
}


// void set_reserve_performance_data(const bool&) method

/// Sets the reserve flag for the performance data.
/// @param new_reserve_performance_data Flag value.

void InputsSelectionAlgorithm::set_reserve_performance_data(const bool& new_reserve_performance_data)
{
    reserve_performance_data = new_reserve_performance_data;
}


// void set_reserve_generalization_performance_data(const bool&) method

/// Sets the reserve flag for the selection performance data.
/// @param new_reserve_generalization_performance_data Flag value.

void InputsSelectionAlgorithm::set_reserve_generalization_performance_data(const bool& new_reserve_generalization_performance_data)
{
    reserve_generalization_performance_data = new_reserve_generalization_performance_data;
}


// void set_reserve_minimal_parameters(const bool&) method

/// Sets the reserve flag for the minimal parameters.
/// @param new_reserve_minimal_parameters Flag value.

void InputsSelectionAlgorithm::set_reserve_minimal_parameters(const bool& new_reserve_minimal_parameters)
{
    reserve_minimal_parameters = new_reserve_minimal_parameters;
}

// void set_performance_calculation_method(const PerformanceCalculationMethod&) method

/// Sets a new method to calculate the performance and the selection performance.
/// @param new_performance_calculation_method Method to calculate the performance (Minimum, Maximum or Mean).

void InputsSelectionAlgorithm::set_performance_calculation_method(const InputsSelectionAlgorithm::PerformanceCalculationMethod& new_performance_calculation_method)
{
    performance_calculation_method = new_performance_calculation_method;
}

// void set_performance_calculation_method(const std::string&) method

/// Sets a new performance calculation method from a string.
/// @param new_performance_calculation_method String with the performance calculation method.

void InputsSelectionAlgorithm::set_performance_calculation_method(const std::string& new_performance_calculation_method)
{
    if (new_performance_calculation_method == "Maximum")
    {
        performance_calculation_method = Maximum;

    }else if (new_performance_calculation_method == "Minimum")
    {
        performance_calculation_method = Minimum;

    }else if (new_performance_calculation_method == "Mean")
    {
        performance_calculation_method = Mean;

    }else{
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void set_performance_calculation_method(const std::string&) method.\n"
               << "Unknown performance calculation method.\n";

        throw std::logic_error(buffer.str());

    }
}


// void set_display(const bool&) method

/// Sets a new display value.
/// If it is set to true messages from this class are to be displayed on the screen;
/// if it is set to false messages from this class are not to be displayed on the screen.
/// @param new_display Display value.

void InputsSelectionAlgorithm::set_display(const bool& new_display)
{
    display = new_display;
}

// void set_selection_performance_goal(const double&) method

/// Sets the Selection performance goal for the inputs selection algorithm.
/// @param new_selection_performance_goal Goal of the selection performance.

void InputsSelectionAlgorithm::set_selection_performance_goal(const double& new_selection_performance_goal)
{
#ifdef __OPENNN_DEBUG__

    if (new_selection_performance_goal < 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void set_selection_performance_goal(const double&) method.\n"
               << "Selection performance goal must be greater or equal than 0.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    selection_performance_goal = new_selection_performance_goal;
}


// void set_maximum_iterations_number(const size_t&) method

/// Sets the maximum iterations number for the inputs selection algorithm.
/// @param new_maximum_iterations_number Maximum number of iterations.

void InputsSelectionAlgorithm::set_maximum_iterations_number(const size_t& new_maximum_iterations_number)
{
    maximum_iterations_number = new_maximum_iterations_number;
}


// void set_maximum_time(const double&) method

/// Sets the maximum time for the inputs selection algorithm.
/// @param new_maximum_time Maximum time for the algorithm.

void InputsSelectionAlgorithm::set_maximum_time(const double& new_maximum_time)
{
#ifdef __OPENNN_DEBUG__

    if (new_maximum_time < 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void set_maximum_time(const double&) method.\n"
               << "Maximum time must be greater than 0.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    maximum_time = new_maximum_time;
}

// void set_maximum_correlation(const double&) method

/// Sets the maximum value for the correlations in the inputs selection algorithm.
/// @param new_maximum_correlation Maximum value of the correlations.

void InputsSelectionAlgorithm::set_maximum_correlation(const double& new_maximum_correlation)
{
#ifdef __OPENNN_DEBUG__

    if (new_maximum_correlation < 0 || new_maximum_correlation > 1)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void set_maximum_correlation(const double&) method.\n"
               << "Maximum correlation must be comprised between 0 and 1.\n";

        throw std::logic_error(buffer.str());
    }

#endif
    maximum_correlation = new_maximum_correlation;
}

// void set_minimum_correlation(const double&) method

/// Sets the minimum value for the correlations in the inputs selection algorithm.
/// @param new_minimum_correlation Minimum value of the correlations.

void InputsSelectionAlgorithm::set_minimum_correlation(const double& new_minimum_correlation)
{
#ifdef __OPENNN_DEBUG__

    if (new_minimum_correlation < 0 || new_minimum_correlation > 1)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void set_minimum_correlation(const double&) method.\n"
               << "Minimum correaltion must be comprised between 0 and 1.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    minimum_correlation = new_minimum_correlation;
}

// void set_tolerance(const double&) method

/// Set the tolerance for the errors in the trainings of the algorithm.
/// @param new_tolerance Value of the tolerance.

void InputsSelectionAlgorithm::set_tolerance(const double& new_tolerance)
{
#ifdef __OPENNN_DEBUG__

    if (new_tolerance < 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void set_tolerance(const double&) method.\n"
               << "Tolerance must be equal or greater than 0.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    tolerance = new_tolerance;
}

// Correlation methods

// Matrix<double> calculate_logistic_correlations(void) const method

/// Returns a matrix with the logistic correlations between all inputs and target variables.
/// The number of rows is the number of inputs variables.
/// The number of columns is the number of target variables.

Matrix<double> InputsSelectionAlgorithm::calculate_logistic_correlations(void) const
{
    // Control sentence (if debug)

    #ifdef __OPENNN_DEBUG__

    std::ostringstream buffer;

    if(!training_strategy_pointer)
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to training strategy is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    // Performance functional stuff


    if(!training_strategy_pointer->has_performance_functional())
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to performance functional is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    if(!training_strategy_pointer->get_performance_functional_pointer()->has_data_set())
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to data set is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    #endif

    // Problem stuff

    const PerformanceFunctional* performance_functional_pointer = training_strategy_pointer->get_performance_functional_pointer();

    const DataSet* data_set_pointer = performance_functional_pointer->get_data_set_pointer();

    const Variables& variables = data_set_pointer->get_variables();

    const size_t inputs_number = variables.count_inputs_number();
    const size_t targets_number = variables.count_targets_number();

    const Vector<size_t> input_indices = variables.arrange_inputs_indices();
    const Vector<size_t> target_indices = variables.arrange_targets_indices();

    Matrix<double> correlations(inputs_number, targets_number);

    for(size_t i = 0; i < inputs_number; i++)
    {
        const Vector<double> inputs = data_set_pointer->get_variable(input_indices[i]);

        for(size_t j = 0; j < targets_number; j++)
        {

            const Vector<double> targets = data_set_pointer->get_variable(target_indices[j]);

            Matrix<double> data(inputs.size(), 2);

            data.set_column(0, inputs);
            data.set_column(1, targets);

            DataSet data_set(data);

            data_set.scale_inputs("MinimumMaximum");

            Instances* instances_pointer = data_set.get_instances_pointer();

            instances_pointer->set_training();

            NeuralNetwork neural_network(1, 1);

            MultilayerPerceptron* multilayer_perceptron_pointer = neural_network.get_multilayer_perceptron_pointer();

            multilayer_perceptron_pointer->set_layer_activation_function(0, Perceptron::Logistic);

            PerformanceFunctional performance_functional(&neural_network, &data_set);

            performance_functional.set_objective_type(PerformanceFunctional::MEAN_SQUARED_ERROR_OBJECTIVE);

            TrainingStrategy training_strategy(&performance_functional);

            training_strategy.set_main_type(TrainingStrategy::LEVENBERG_MARQUARDT_ALGORITHM);

            training_strategy.set_display(false);

            training_strategy.get_Levenberg_Marquardt_algorithm_pointer()->set_performance_goal(0.0);

            training_strategy.get_Levenberg_Marquardt_algorithm_pointer()->set_gradient_norm_goal(0.0);

            training_strategy.get_Levenberg_Marquardt_algorithm_pointer()->set_minimum_performance_increase(0.0);

            training_strategy.perform_training();

            const Vector<double> outputs = neural_network.calculate_output_data(inputs.to_column_matrix()).to_vector();

            correlations(i,j) = targets.calculate_linear_correlation(outputs);
        }
    }

    return(correlations);
}

// Vector<double> calculate_final_correlations(void) const method

/// Calculate the correlation depending on whether the problem is a linear regression or a pattern recognition.
/// Return the absolute value of the correlation.
/// If there are many targets in the data set it returns the sum of the absolute values.

Vector<double> InputsSelectionAlgorithm::calculate_final_correlations(void) const
{
    Vector<double> final_correlations;
    Matrix<double> correlations;

    DataSet* data_set = training_strategy_pointer->get_performance_functional_pointer()->get_data_set_pointer();

    if (regression)
    {
        correlations = data_set->calculate_linear_correlations();
        correlations = correlations.calculate_absolute_value();

    }else
    {
        correlations = calculate_logistic_correlations();
    }

    final_correlations.resize(correlations.get_rows_number());

    for(size_t i = 0; i < final_correlations.size(); i++)
        for(size_t j = 0; j < correlations.get_columns_number(); j ++)
            final_correlations[i] += correlations(i,j);

    return final_correlations;
}

// Performances calculation methods


// void set_neural_inputs(const Vector<bool>&) method

/// Sets the neural network with the number of inputs encoded in the vector.
/// This method used the grow and prune inputs methods.
/// @param inputs Vector with the inputs to be set.

void InputsSelectionAlgorithm::set_neural_inputs(const Vector<bool>& inputs)
{
    const PerformanceFunctional* performance_functional_pointer = training_strategy_pointer->get_performance_functional_pointer();
    NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

    const size_t current_inputs_number = inputs.count_occurrences(true);
    const size_t neural_network_inputs_number = neural_network_pointer->get_inputs_number();

    if (current_inputs_number < neural_network_inputs_number)
    {
        for (size_t j = current_inputs_number; j < neural_network_inputs_number; j++)
            neural_network_pointer->prune_input(0);
    }else
    {
        for (size_t j = neural_network_inputs_number; j < current_inputs_number; j++)
            neural_network_pointer->grow_input();
    }

    neural_network_pointer->perturbate_parameters(0.5);
}


// Vector<double> calculate_minimum_final_performances(const Vector<bool>&) method

/// Returns the minimum of the performance and selection performance in trials_number trainings.
/// @param inputs Vector of the inputs to be trained with.

Vector<double> InputsSelectionAlgorithm::calculate_minimum_final_performances(const Vector<bool>& inputs)
{
#ifdef __OPENNN_DEBUG__

    if(inputs.count_occurrences(true) <= 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> calculate_minimum_final_performances(size_t) method.\n"
               << "Number of inputs must be greater or equal than 1.\n";

        throw std::logic_error(buffer.str());
    }

    if(trials_number <= 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> calculate_minimum_final_performances(size_t) method.\n"
               << "Number of parameters assay must be greater than 0.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    NeuralNetwork* neural_network = training_strategy_pointer->get_performance_functional_pointer()->get_neural_network_pointer();

    TrainingStrategy::Results training_strategy_results;

    Vector<double> final(2);
    final[0] = 10;
    final[1] = 10;

    Vector<double> current_performance(2);

    Vector<double> final_parameters;

    bool flag_performance = false;
    bool flag_generalization = false;

    for (size_t i = 0; i < inputs_history.size(); i++)
    {
        if (inputs_history[i] == inputs)
        {
            final[0] = performance_history[i];
            flag_performance = true;
        }
    }

    for (size_t i = 0; i < inputs_history.size(); i++)
    {
        if (inputs_history[i] == inputs)
        {
            final[1] = generalization_performance_history[i];
            flag_generalization = true;
        }
    }

    if (flag_performance && flag_generalization)
        return(final);

    neural_network->perturbate_parameters(0.5);
    training_strategy_results = training_strategy_pointer->perform_training();

    current_performance = get_final_performances(training_strategy_results);

    final[0] = current_performance[0];
    final[1] = current_performance[1];

    final_parameters.set(neural_network->arrange_parameters());

    for (size_t i = 1; i < trials_number; i++)
    {
        neural_network->randomize_parameters_normal();

        training_strategy_results = training_strategy_pointer->perform_training();

        current_performance = get_final_performances(training_strategy_results);

        if (!flag_performance && final[0] > current_performance[0])
        {
            final[0] = current_performance[0];

            final_parameters.set(neural_network->arrange_parameters());
        }

        if (!flag_generalization && final[1] > current_performance[1])
        {
            final[1] = current_performance[1];

            final_parameters.set(neural_network->arrange_parameters());
        }

    }


    inputs_history.push_back(inputs);

    performance_history.push_back(final[0]);

    generalization_performance_history.push_back(final[1]);

    parameters_history.push_back(final_parameters);


    return final;
}


// Vector<double> calculate_maximum_final_performances(const Vector<bool>&) const method

/// Returns the maximum of the performance and selection performance in trials_number trainings.
/// @param inputs Vector of the inputs to be trained with.

Vector<double> InputsSelectionAlgorithm::calculate_maximum_final_performances(const Vector<bool>& inputs)
{
#ifdef __OPENNN_DEBUG__

    if(inputs.count_occurrences(true) <= 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> calculate_minimum_final_performances(size_t) method.\n"
               << "Number of inputs must be greater or equal than 1.\n";

        throw std::logic_error(buffer.str());
    }

    if(trials_number <= 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> calculate_minimum_final_performances(size_t) method.\n"
               << "Number of parameters assay must be greater than 0.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    NeuralNetwork* neural_network = training_strategy_pointer->get_performance_functional_pointer()->get_neural_network_pointer();

    TrainingStrategy::Results training_strategy_results;

    Vector<double> final(2);
    final[0] = 0;
    final[1] = 0;

    Vector<double> current_performance(2);

    Vector<double> final_parameters;

    bool flag_performance = false;
    bool flag_generalization = false;

    for (size_t i = 0; i < inputs_history.size(); i++)
    {
        if (inputs_history[i] == inputs)
        {
            final[0] = performance_history[i];
            flag_performance = true;
        }
    }

    for (size_t i = 0; i < inputs_history.size(); i++)
    {
        if (inputs_history[i] == inputs)
        {
            final[1] = generalization_performance_history[i];
            flag_generalization = true;
        }
    }

    if (flag_performance && flag_generalization)
        return(final);

    neural_network->perturbate_parameters(0.5);
    training_strategy_results = training_strategy_pointer->perform_training();

    current_performance = get_final_performances(training_strategy_results);

    final[0] = current_performance[0];
    final[1] = current_performance[1];

    final_parameters.set(neural_network->arrange_parameters());

    for (size_t i = 1; i < trials_number; i++)
    {
        neural_network->randomize_parameters_normal();

        training_strategy_results = training_strategy_pointer->perform_training();

        current_performance = get_final_performances(training_strategy_results);

        if (!flag_performance && final[0] < current_performance[0])
        {
            final[0] = current_performance[0];

            final_parameters.set(neural_network->arrange_parameters());
        }

        if (!flag_generalization && final[1] < current_performance[1])
        {
            final[1] = current_performance[1];

            final_parameters.set(neural_network->arrange_parameters());
        }

    }

    inputs_history.push_back(inputs);

    performance_history.push_back(final[0]);

    generalization_performance_history.push_back(final[1]);

    parameters_history.push_back(final_parameters);

    return final;
}


// Vector<double> calculate_mean_final_performances(const Vector<bool>&) method

/// Returns the mean of the performance and selection performance in trials_number trainings.
/// @param inputs Vector of the inputs to be trained with.

Vector<double> InputsSelectionAlgorithm::calculate_mean_final_performances(const Vector<bool> &inputs)
{
#ifdef __OPENNN_DEBUG__

    if(inputs.count_occurrences(true) <= 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> calculate_minimum_final_performances(size_t) method.\n"
               << "Number of inputs must be greater or equal than 1.\n";

        throw std::logic_error(buffer.str());
    }

    if(trials_number <= 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> calculate_minimum_final_performances(size_t) method.\n"
               << "Number of parameters assay must be greater than 0.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    NeuralNetwork* neural_network = training_strategy_pointer->get_performance_functional_pointer()->get_neural_network_pointer();

    TrainingStrategy::Results training_strategy_results;

    Vector<double> mean_final(2);
    mean_final[0] = 0;
    mean_final[1] = 0;

    Vector<double> current_performance(2);

    Vector<double> final_parameters;

    bool flag_performance = false;
    bool flag_generalization = false;

    for (size_t i = 0; i < inputs_history.size(); i++)
    {
        if (inputs_history[i] == inputs)
        {
            mean_final[0] = performance_history[i];
            flag_performance = true;
        }
    }

    for (size_t i = 0; i < inputs_history.size(); i++)
    {
        if (inputs_history[i] == inputs)
        {
            mean_final[1] = generalization_performance_history[i];
            flag_generalization = true;
        }
    }

    if (flag_performance && flag_generalization)
        return(mean_final);

    neural_network->perturbate_parameters(0.5);
    training_strategy_results = training_strategy_pointer->perform_training();

    current_performance = get_final_performances(training_strategy_results);

    mean_final[0] = current_performance[0];
    mean_final[1] = current_performance[1];

    final_parameters.set(neural_network->arrange_parameters());

    for (size_t i = 1; i < trials_number; i++)
    {
        neural_network->randomize_parameters_normal();

        training_strategy_results = training_strategy_pointer->perform_training();

        current_performance = get_final_performances(training_strategy_results);

        if (!flag_performance)
            mean_final[0] += current_performance[0]/trials_number;
        if (!flag_generalization)
            mean_final[1] += current_performance[1]/trials_number;

    }

    inputs_history.push_back(inputs);

    performance_history.push_back(mean_final[0]);

    generalization_performance_history.push_back(mean_final[1]);

    parameters_history.push_back(final_parameters);

    return mean_final;
}

// Vector<double> get_final_performances(const TrainingStrategy::Results&) method

/// Return final training performance and final selection performance depending on the training method.
/// @param results Results of the perform_training method.

Vector<double> InputsSelectionAlgorithm::get_final_performances(const TrainingStrategy::Results& results)
{
    Vector<double> performances(2);
    switch(training_strategy_pointer->get_main_type())
    {
    case TrainingStrategy::NO_MAIN:
    {
        performances[0] = 0;
        performances[1] = 0;
        break;
    }
    case TrainingStrategy::GRADIENT_DESCENT:
    {
        performances[0] = results.gradient_descent_results_pointer->final_performance;
        performances[1] = results.gradient_descent_results_pointer->final_generalization_performance;
        break;
    }
    case TrainingStrategy::CONJUGATE_GRADIENT:
    {
        performances[0] = results.conjugate_gradient_results_pointer->final_performance;
        performances[1] = results.conjugate_gradient_results_pointer->final_generalization_performance;
        break;
    }
    case TrainingStrategy::QUASI_NEWTON_METHOD:
    {
        performances[0] = results.quasi_Newton_method_results_pointer->final_performance;
        performances[1] = results.quasi_Newton_method_results_pointer->final_generalization_performance;
        break;
    }
    case TrainingStrategy::LEVENBERG_MARQUARDT_ALGORITHM:
    {
        performances[0] = results.Levenberg_Marquardt_algorithm_results_pointer->final_performance;
        performances[1] = results.Levenberg_Marquardt_algorithm_results_pointer->final_generalization_performance;
        break;
    }
    case TrainingStrategy::USER_MAIN:
    {
        performances[0] = 0;
        performances[1] = 0;
        break;
    }
    default:
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> get_final_performances(const TrainingStrategy::Results) method.\n"
               << "Unknown main type method.\n";

        throw std::logic_error(buffer.str());
    }
    }

    return(performances);
}

// Vector<double> calculate_performances(const Vector<bool>&) method

/// Return performance and generalization depending on the performance calculation method.
/// @param inputs Vector of inputs to be trained with.

Vector<double> InputsSelectionAlgorithm::calculate_performances(const Vector<bool>& inputs)
{
    switch (performance_calculation_method)
    {
    case Maximum:
        return(calculate_maximum_final_performances(inputs));
    case Minimum:
        return(calculate_minimum_final_performances(inputs));
    case Mean:
        return(calculate_mean_final_performances(inputs));
    default:
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> calculate_performances(const size_t) method.\n"
               << "Unknown performance calculation method.\n";

        throw std::logic_error(buffer.str());
    }
    }
}


// Vector<double> get_parameters_inputs(const Vector<bool>&) method

/// Returns the parameters of the neural network if the inputs is in the history.
/// @param inputs Vector of inputs to be trained with.

Vector<double> InputsSelectionAlgorithm::get_parameters_inputs(const Vector<bool>& inputs)
{
#ifdef __OPENNN_DEBUG__

    if (inputs.count_occurrences(true) <= 0)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> get_parameters_inputs(const size_t&) method.\n"
               << "inputs must be greater than 1.\n";

        throw std::logic_error(buffer.str());
    }

#endif

    size_t i;
    Vector<double> parameters;

    for (i = 0; i < inputs_history.size(); i++)
    {
        if (inputs_history[i] == inputs)
        {
            parameters = parameters_history[i];
            break;
        }
    }

    if (i == inputs_history.size())
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "Vector<double> get_parameters_inputs(const size_t&) method.\n"
               << "inputs not found in the parameter_history.\n";

        throw std::logic_error(buffer.str());
    }else
        return(parameters);
}

// void delete_generalization_history(void) method

/// Delete the history of the selection performance values.

void InputsSelectionAlgorithm::delete_generalization_history(void)
{
    generalization_performance_history.set();
}

// void delete_performance_history(void) method

/// Delete the history of the performance values.

void InputsSelectionAlgorithm::delete_performance_history(void)
{
    performance_history.set();
}

// void delete_parameters_history(void) method

/// Delete the history of the parameters of the trained neural networks.

void InputsSelectionAlgorithm::delete_parameters_history(void)
{
    parameters_history.set();
}

// void check(void) const method

/// Checks that the different pointers needed for performing the inputs selection are not NULL.

void InputsSelectionAlgorithm::check(void) const
{
    // Training algorithm stuff

    std::ostringstream buffer;

    if(!training_strategy_pointer)
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to training strategy is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    // Performance functional stuff


    if(!training_strategy_pointer->has_performance_functional())
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to performance functional is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    const PerformanceFunctional* performance_functional_pointer = training_strategy_pointer->get_performance_functional_pointer();

    // Neural network stuff

    if(!performance_functional_pointer->has_neural_network())
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to neural network is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    const NeuralNetwork* neural_network_pointer = performance_functional_pointer->get_neural_network_pointer();

    if(!neural_network_pointer->has_multilayer_perceptron())
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to multilayer perceptron is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    const MultilayerPerceptron* multilayer_perceptron_pointer = neural_network_pointer->get_multilayer_perceptron_pointer();


    if(multilayer_perceptron_pointer->is_empty())
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Multilayer Perceptron is empty.\n";

        throw std::logic_error(buffer.str());
    }

    /*
   if(multilayer_perceptron_pointer->get_layers_number() != 2)
   {
      buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
             << "void check(void) const method.\n"
             << "Number of layers in multilayer perceptron (" << multilayer_perceptron_pointer->get_layers_number() << ") must be 2.\n";

      throw std::logic_error(buffer.str());
   }*/


    // Data set stuff


    if(!performance_functional_pointer->has_data_set())
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Pointer to data set is NULL.\n";

        throw std::logic_error(buffer.str());
    }

    const DataSet* data_set_pointer = performance_functional_pointer->get_data_set_pointer();

    const Instances& instances = data_set_pointer->get_instances();

    const size_t generalization_instances_number = instances.count_generalization_instances_number();

    if(generalization_instances_number == 0)
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void check(void) const method.\n"
               << "Number of generalization instances is zero.\n";

        throw std::logic_error(buffer.str());
    }

}
/*
// tinyxml2::XMLDocument* to_XML(void) const method

/// Serializes the input selection object into a XML document of the TinyXML library.
/// See the OpenNN manual for more information about the format of this document.

tinyxml2::XMLDocument* InputsSelectionAlgorithm::to_XML(void) const
{
    tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

    std::ostringstream buffer;

    // Input input selection

    tinyxml2::XMLElement* inputs_selection_element = document->NewElement("InputsSelectionAlgorithm");

    document->InsertFirstChild(inputs_selection_element);

    // Hidden layer sizes

    tinyxml2::XMLElement* input_numbers_element = document->NewElement("InputsNumbers");
    inputs_selection_element->LinkEndChild(input_numbers_element);

    tinyxml2::XMLElement* maximum_input_element = document->NewElement("MaximumInputNumber");
    input_numbers_element->LinkEndChild(maximum_input_element);

    buffer.str("");
    buffer << maximum_input;

    tinyxml2::XMLText* maximum_input_text = document->NewText(buffer.str().c_str());
    maximum_input_element->LinkEndChild(maximum_input_text);

    tinyxml2::XMLElement* minimum_input_element = document->NewElement("MinimumInputNumber");
    input_numbers_element->LinkEndChild(minimum_input_element);

    buffer.str("");
    buffer << minimum_input;

    tinyxml2::XMLText* minimum_input_text = document->NewText(buffer.str().c_str());
    minimum_input_element->LinkEndChild(minimum_input_text);


    // ParametersAssaysNumber

    tinyxml2::XMLElement* trials_number_element = document->NewElement("ParametersAssaysNumber");
    inputs_selection_element->LinkEndChild(trials_number_element);

    buffer.str("");
    buffer << trials_number;

    tinyxml2::XMLText* trials_number_text = document->NewText(buffer.str().c_str());
    trials_number_element->LinkEndChild(trials_number_text);


    // Display

    tinyxml2::XMLElement* display_element = document->NewElement("Display");
    inputs_selection_element->LinkEndChild(display_element);

    buffer.str("");
    buffer << display;

    tinyxml2::XMLText* display_text = document->NewText(buffer.str().c_str());
    display_element->LinkEndChild(display_text);


    return(document);
}


// void from_XML(const tinyxml2::XMLDocument&) method

/// @todo

void InputsSelectionAlgorithm::from_XML(const tinyxml2::XMLDocument&)
{
}


// void print(void) method

/// Prints to the screen the XML representation of this input selection object.

void InputsSelectionAlgorithm::print(void) const
{
    std::cout << to_XML();
}


// void save(const std::string&) const method

/// Saves the input selection members to a XML file.
/// @param file_name Name of input selection XML file.

void InputsSelectionAlgorithm::save(const std::string& file_name) const
{
    tinyxml2::XMLDocument* document = to_XML();

    document->SaveFile(file_name.c_str());

    delete document;
}


// void load(const std::string&) method

/// Loads the input selection members from a XML file.
/// @param file_name Name of input selection XML file.

void InputsSelectionAlgorithm::load(const std::string& file_name)
{
    std::ostringstream buffer;

    tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;

    if(document->LoadFile(file_name.c_str()))
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void load(const std::string&) method.\n"
               << "Cannot load XML file " << file_name << ".\n";

        throw std::logic_error(buffer.str());
    }

    // Root

    tinyxml2::XMLElement* inputs_selection_element = document->FirstChildElement("InputsSelectionAlgorithm");

    if(!inputs_selection_element)
    {
        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "void load(const std::string&) method.\n"
               << "Invalid input input selection XML root element.\n";

        throw std::logic_error(buffer.str());
    }

    // Hidden layer sizes


    // Parameters assays number

    tinyxml2::XMLElement* trials_number_element = inputs_selection_element->FirstChildElement("ParametersAssaysNumber");

    if(trials_number_element)
    {
        trials_number = atoi(trials_number_element->GetText());
    }
}
*/

// std::string write_stopping_condition(void) const method

/// Return a string with the stopping condition of the InputsSelectionResults

std::string InputsSelectionAlgorithm::InputsSelectionResults::write_stopping_condition(void) const
{
    switch (stopping_condition)
    {
    case MaximumTime:
    {
        return ("MaximumTime");
    }
    case SelectionPerformanceGoal:
    {
        return("SelectionPerformanceGoal");
    }
    case MaximumIterations:
    {
        return("MaximumIterations");
    }
    case MaximumSelectionFailures:
    {
        return("MaximumSelectionFailures");
    }
    case CorrelationGoal:
    {
        return("CorrelationGoal");
    }
    case AlgorithmFinished:
    {
        return("AlgorithmFinished");
    }
    default:
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionResults struct.\n"
               << "std::string write_stopping_condition(void) const method.\n"
               << "Unknown stopping condition type.\n";

        throw std::logic_error(buffer.str());

        break;
    }
    }

}


// std::string to_string(void) const method

/// Returns a string representation of the current inputs selection results structure.

std::string InputsSelectionAlgorithm::InputsSelectionResults::to_string(void) const
{
   std::ostringstream buffer;

   // Inputs history

   if(!inputs_data.empty())
   {
     buffer << "% Inputs history:\n"
            << inputs_data.to_row_matrix() << "\n";
   }


   // Parameters history

   if(!parameters_data.empty())
   {
     buffer << "% Parameters history:\n"
            << parameters_data.to_row_matrix() << "\n";
   }

   // Performance history

   if(!performance_data.empty())
   {
       buffer << "% Performance history:\n"
              << performance_data.to_row_matrix() << "\n";
   }

   // Selection performance history

   if(!generalization_performance_data.empty())
   {
       buffer << "% Selection performance history:\n"
              << generalization_performance_data.to_row_matrix() << "\n";
   }

   // Minimal parameters

   if(!minimal_parameters.empty())
   {
       buffer << "% Minimal parameters:\n"
              << minimal_parameters << "\n";
   }

   // Stopping condition

   buffer << "% Stopping condition\n"
          << write_stopping_condition() << "\n";

   // Optimum selection performance

   if (final_generalization_performance != 0)
   {
       buffer << "% Optimum selection performance:\n"
              << final_generalization_performance << "\n";
   }

   // Final performance

   if (final_performance != 0)
   {
       buffer << "% Final performance:\n"
              << final_performance << "\n";
   }

   // Optimal input

   if (!optimal_inputs.empty())
   {
       buffer << "% Optimal input:\n"
              << optimal_inputs << "\n";
   }

   // Iterations number


   buffer << "% Number of iterations:\n"
          << iterations_number << "\n";


   // Elapsed time

   buffer << "% Elapsed time:\n"
          << elapsed_time << "\n";



   return(buffer.str());
}

// size_t get_input_index(const Vector<Variables::Use>, const size_t) method

/// Return the index of uses where is the (input_number)-th input.
/// @param uses vector of the uses of the variables.
/// @param input_number index of the input to find.

size_t InputsSelectionAlgorithm::get_input_index(const Vector<Variables::Use> uses, const size_t input_number)
{
#ifdef __OPENNN_DEBUG__

    if (uses.size() < input_number)
    {
        std::ostringstream buffer;

        buffer << "OpenNN Exception: InputsSelectionAlgorithm class.\n"
               << "const size_t get_input_index(const Vector<Variables::Use>, const size_t) method.\n"
               << "Size of uses vector must be greater than " <<  input_number << ".\n";

        throw std::logic_error(buffer.str());
    }
#endif

    size_t i = 0;
    size_t j = 0;
    while(i < uses.size())
    {
        if (uses[i] == Variables::Input &&
            input_number == j)
        {
            break;
        }else if (uses[i] == Variables::Input)
        {
            i++;
            j++;
        }else
        {
            i++;
        }
    }
    return i;
}

}



