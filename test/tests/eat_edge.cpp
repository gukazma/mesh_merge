#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Polygon_mesh_processing/IO/polygon_mesh_io.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Polygon_mesh_processing/polygon_mesh_to_polygon_soup.h>
#include <CGAL/Polygon_mesh_processing/polygon_soup_to_polygon_mesh.h>
#include <unordered_set>
#include <CGAL/draw_surface_mesh.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point_3;
typedef CGAL::Surface_mesh<Point_3> Surface_Mesh;
typedef std::array<std::size_t, 3> Facet; // ����������
int eat_edge()
{
	Surface_Mesh mesh0;
	Surface_Mesh mesh1;

	CGAL::Polygon_mesh_processing::IO::read_polygon_mesh("./mesh0.ply", mesh0);
	CGAL::Polygon_mesh_processing::IO::read_polygon_mesh("./mesh1.ply", mesh1);
	for (auto aaa : mesh0.edges())
	{
		std::cout << aaa << std::endl;
	} 
	std::vector<Point_3> vertices;
	std::vector<Facet> facets;
	CGAL::Polygon_mesh_processing::polygon_mesh_to_polygon_soup(mesh0, vertices, facets);
	Surface_Mesh meshtmp;
	CGAL::Polygon_mesh_processing::polygon_soup_to_polygon_mesh(vertices, facets, meshtmp);

	
	CGAL::draw(mesh0);
	CGAL::draw(mesh1);
	CGAL::draw(meshtmp);
	
	return 0;
}