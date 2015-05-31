#pragma once

#include <application.hpp>
#include <context.hpp>

#include <orm/sqlite.hpp>

class app : public mvcpp::application
{
public:
    app(unsigned short port) : application(port)
    {
        set_default_template("template");

        mvcpp::database::current_database = new mvcpp::sqlite("data.db"); // start database

        // Register all controllers
        // register_controller<home_controller>();

        // Register all models
        // model_name::create_tables(true);
    }
    virtual void initialize_default_template(mvcpp::context::ptr ctx) override
    {
        ctx->get_template().subview("MENU") = ctx->get_view("_menu");
        ctx->get_template()["TITLE"] = "i++ | Customizable customers and invoicing system";
    }
};
