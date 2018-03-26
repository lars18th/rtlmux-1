/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.6
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_C_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_C_PACKAGE "rtlmux"
#endif

#ifndef CMDLINE_C_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_C_PACKAGE_NAME "rtlmux"
#endif

#ifndef CMDLINE_C_VERSION
/** @brief the program version */
#define CMDLINE_C_VERSION "1.0.0"
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  int port_arg;	/**< @brief rtl_tcp port (default='1234').  */
  char * port_orig;	/**< @brief rtl_tcp port original value given at command line.  */
  const char *port_help; /**< @brief rtl_tcp port help description.  */
  char * host_arg;	/**< @brief rtl_tcp host address (default='localhost').  */
  char * host_orig;	/**< @brief rtl_tcp host address original value given at command line.  */
  const char *host_help; /**< @brief rtl_tcp host address help description.  */
  int listen_arg;	/**< @brief Listening port for client connections (default='7878').  */
  char * listen_orig;	/**< @brief Listening port for client connections original value given at command line.  */
  const char *listen_help; /**< @brief Listening port for client connections help description.  */
  int delayed_flag;	/**< @brief Delayed 
  connection to the server (default=off).  */
  const char *delayed_help; /**< @brief Delayed 
  connection to the server help description.  */
  int restart_flag;	/**< @brief Restart server's connection when last 
  client disconnects (default=off).  */
  const char *restart_help; /**< @brief Restart server's connection when last 
  client disconnects help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int port_given ;	/**< @brief Whether port was given.  */
  unsigned int host_given ;	/**< @brief Whether host was given.  */
  unsigned int listen_given ;	/**< @brief Whether listen was given.  */
  unsigned int delayed_given ;	/**< @brief Whether delayed was given.  */
  unsigned int restart_given ;	/**< @brief Whether restart was given.  */

} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_c_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief the description string of the program */
extern const char *gengetopt_args_info_description;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_c (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_c_ext() instead
 */
int cmdline_c2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_c_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_c_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_c_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_c_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_c_print_help(void);
/**
 * Print the version
 */
void cmdline_c_print_version(void);

/**
 * Initializes all the fields a cmdline_c_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_c_params_init(struct cmdline_c_params *params);

/**
 * Allocates dynamically a cmdline_c_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_c_params structure
 */
struct cmdline_c_params *cmdline_c_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_c_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_c_free (struct gengetopt_args_info *args_info);

/**
 * The config file parser (deprecated version)
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_c_config_file() instead
 */
int cmdline_c_configfile (const char *filename,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The config file parser
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_c_config_file (const char *filename,
  struct gengetopt_args_info *args_info,
  struct cmdline_c_params *params);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_c_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
