#include "includes/parser.h"
#include <stdio.h>
#include <stdlib.h>

static void initialize_scene(t_scene *scene)
{
    scene->ambient.ratio = 0.0;
    scene->ambient.color = (t_color){0, 0, 0};

    scene->camera.position = (t_vec3){0, 0, 0};
    scene->camera.orientation = (t_vec3){0, 0, 0};
    scene->camera.fov = 0;

    scene->lights = NULL;
    scene->spheres = NULL;
    scene->planes = NULL;
    scene->cylinders = NULL;
}

static void print_spheres(t_scene *scene)
{
    printf("\n--- Spheres ---\n");
    t_sphere *sphere = scene->spheres;
    while (sphere)
    {
        printf("Sphere: center = (%f, %f, %f), radius = %f, color = (%d, %d, %d)\n",
               sphere->center.x, sphere->center.y, sphere->center.z,
               sphere->radius,
               sphere->color.r, sphere->color.g, sphere->color.b);
        sphere = sphere->next;
    }
}

static void print_planes(t_scene *scene)
{
    printf("\n--- Planes ---\n");
    t_plane *plane = scene->planes;
    while (plane)
    {
        printf("Plane: point = (%f, %f, %f), normal = (%f, %f, %f), color = (%d, %d, %d)\n",
               plane->point.x, plane->point.y, plane->point.z,
               plane->normal.x, plane->normal.y, plane->normal.z,
               plane->color.r, plane->color.g, plane->color.b);
        plane = plane->next;
    }
}

static void print_cylinders(t_scene *scene)
{
    printf("\n--- Cylinders ---\n");
    t_cylinder *cylinder = scene->cylinders;
    while (cylinder)
    {
        printf("Cylinder: base = (%f, %f, %f), direction = (%f, %f, %f), radius = %f, height = %f, color = (%d, %d, %d)\n",
               cylinder->base.x, cylinder->base.y, cylinder->base.z,
               cylinder->direction.x, cylinder->direction.y, cylinder->direction.z,
               cylinder->radius,
               cylinder->height,
               cylinder->color.r, cylinder->color.g, cylinder->color.b);
        cylinder = cylinder->next;
    }
}

static void print_scene(t_scene *scene)
{
    printf("\n--- Scene Loaded ---\n");
    printf("Ambient Light: ratio = %f, color = (%d, %d, %d)\n",
           scene->ambient.ratio,
           scene->ambient.color.r,
           scene->ambient.color.g,
           scene->ambient.color.b);

    printf("Camera: position = (%f, %f, %f), orientation = (%f, %f, %f), FOV = %f\n",
           scene->camera.position.x, scene->camera.position.y, scene->camera.position.z,
           scene->camera.orientation.x, scene->camera.orientation.y, scene->camera.orientation.z,
           scene->camera.fov);

    t_light *light = scene->lights;
    while (light)
    {
        printf("Light: position = (%f, %f, %f), brightness = %f, color = (%d, %d, %d)\n",
               light->position.x, light->position.y, light->position.z,
               light->brightness,
               light->color.r, light->color.g, light->color.b);
        light = light->next;
    }
    print_spheres(scene);
    print_planes(scene);
    print_cylinders(scene);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <scene_file.rt>\n", argv[0]);
        return (1);
    }

    t_scene scene;
    initialize_scene(&scene); 
    
    read_rt_file(argv[1], &scene);  // 🔥 Aquí llamas a tu función para parsear el archivo

    // Imprimimos la escena para comprobar
    print_scene(&scene);

    return (0);
}