#include <Blitz/Blitz-Core.hpp>

char* vertexShader = R"(#version 330 core
layout (location = 0) in vec3 a_Pos;
layout (location = 2) in vec2 a_TexCoord;
    
out vec2 v_TexCoord;

uniform mat4 u_viewProjection = mat4(1.0);
uniform mat4 u_transform = mat4(1.0);

void main()
{
    v_TexCoord = a_TexCoord;
    gl_Position =  u_viewProjection * u_transform * vec4(a_Pos, 1.0);
})";

char* fragmentShader = R"(#version 330 core
uniform vec4 u_Color = vec4(1.0, 1.0, 1.0, 1.0);
uniform sampler2D u_Texture;
                
out vec4 Color;
in vec2 v_TexCoord;

void main()
{
    Color = u_Color * texture2D(u_Texture, v_TexCoord); // vec4(v_TexCoord, 0, 1);
})";

float verts[] = {
     1.0f,  1.0f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f,
     1.0f, -1.0f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f,
    -1.0f, -1.0f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
    -1.0f,  1.0f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f
};

Blitz::uint indices[] = {
    0, 1, 3,
    1, 2, 3
};

void BlitzCheckKeys(GLFWwindow* window, Blitz::Camera& camera) {
    if(glfwGetKey(window, GLFW_KEY_W)) {
        camera.Move({ 0.0f, 0.1f, 0.0f });
    } else if(glfwGetKey(window, GLFW_KEY_S)) {
        camera.Move({ 0.0f, -0.1f, 0.0f });
    }

    if(glfwGetKey(window, GLFW_KEY_A)) {
        camera.Move({ -0.1f, 0.0f, 0.0f });
    } else if(glfwGetKey(window, GLFW_KEY_D)) {
        camera.Move({ 0.1f, 0.0f, 0.0f });
    }
}

glm::mat4 transform = glm::mat4(1);

int main(int argv, char** argc) {
    if(!glfwInit()) {
        std::cerr << "GLFW Init Error!\n";
        return BLITZ_NULL;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #if defined(BLITZ_APPLE)
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    #endif
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    Blitz::Window window;
    window.SetIcon("icon.png");

    gladLoadGL();
    BlitzGLCall(glViewport(0, 0, 1280, 720));

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    ImGui_ImplGlfw_InitForOpenGL(window.GetWindow(), BLITZ_TRUE);
    ImGui_ImplOpenGL3_Init("#version 330 core");

    ImGui::StyleColorsDark();

    Blitz::Shader shader(vertexShader, fragmentShader);

    Blitz::VertexArray vao;
    Blitz::VertexBuffer vbo;
    vbo.SetData(sizeof(verts), verts);
    Blitz::IndexBuffer ibo;
    ibo.SetData(sizeof(indices), indices);

    // position attribute
    BlitzGLCall(glEnableVertexAttribArray(0));
    BlitzGLCall(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0));
    // color attribute
    BlitzGLCall(glEnableVertexAttribArray(1));
    BlitzGLCall(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float))));
    // texture coord attribute
    BlitzGLCall(glEnableVertexAttribArray(2));
    BlitzGLCall(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float))));

    Blitz::Texture texture;
    texture.LoadTexture("banner.png");

    Blitz::Camera camera;

    transform = glm::scale(transform, glm::vec3(0.6f, 0.2f, 0.2f));

    Blitz::uint u_viewProjection = shader.GetUniformLocation("u_viewProjection");
    Blitz::uint u_transform = shader.GetUniformLocation("u_transform");

    float color[3] = { 42.0f, 135.0f, 212.0f };

    while(window.IsOpen()) {
        BlitzCheckKeys(window.GetWindow(), camera);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(color[0], color[1], color[2], 1.0f);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        shader.Bind();

        camera.SetViewProjection(u_viewProjection);

        BlitzGLCall(glUniformMatrix4fv(u_transform, 1, BLITZ_FALSE, glm::value_ptr(transform)));

        texture.Bind();
        vao.Bind();
        BlitzGLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
        vao.Unbind();
        texture.Unbind();

        ImGui::Begin("Blitz ImGui Window");
        ImGui::ColorEdit3("Background color", color);
        ImGui::End();


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window.Display();
        glfwPollEvents();
    }

    Blitz::Exit();
    return BLITZ_NULL;
}