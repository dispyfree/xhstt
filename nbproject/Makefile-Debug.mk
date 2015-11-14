#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/base/cost/Cost.o \
	${OBJECTDIR}/base/cost/CostFunction.o \
	${OBJECTDIR}/base/event/Event.o \
	${OBJECTDIR}/base/event/EventGroup.o \
	${OBJECTDIR}/base/event/EventGroupKind.o \
	${OBJECTDIR}/base/event/EventResource.o \
	${OBJECTDIR}/base/event/EventResourceGroup.o \
	${OBJECTDIR}/base/event/SubEvent.o \
	${OBJECTDIR}/base/file/Archive.o \
	${OBJECTDIR}/base/file/ArchiveMetaData.o \
	${OBJECTDIR}/base/file/Instance.o \
	${OBJECTDIR}/base/file/InstanceMetaData.o \
	${OBJECTDIR}/base/resource/Resource.o \
	${OBJECTDIR}/base/resource/ResourceGroup.o \
	${OBJECTDIR}/base/resource/ResourceType.o \
	${OBJECTDIR}/base/solution/Solution.o \
	${OBJECTDIR}/base/solution/SolutionGroup.o \
	${OBJECTDIR}/base/solution/SolutionGroupMetaData.o \
	${OBJECTDIR}/base/solution/Task.o \
	${OBJECTDIR}/base/tests.o \
	${OBJECTDIR}/base/time/Meet.o \
	${OBJECTDIR}/base/time/Time.o \
	${OBJECTDIR}/base/time/TimeGroup.o \
	${OBJECTDIR}/base/time/TimeSpread.o \
	${OBJECTDIR}/constraint/AssignResourceConstraint.o \
	${OBJECTDIR}/constraint/AssignTimeConstraint.o \
	${OBJECTDIR}/constraint/AvoidClashesConstraint.o \
	${OBJECTDIR}/constraint/AvoidSplitAssignmentsConstraint.o \
	${OBJECTDIR}/constraint/AvoidUnavailableTimesConstraint.o \
	${OBJECTDIR}/constraint/ClusterBusyTimesConstraint.o \
	${OBJECTDIR}/constraint/Constraint.o \
	${OBJECTDIR}/constraint/DistributeSplitEventsConstraint.o \
	${OBJECTDIR}/constraint/LimitBusyTimesConstraint.o \
	${OBJECTDIR}/constraint/LimitIdleTimesConstraint.o \
	${OBJECTDIR}/constraint/LimitWorkloadConstraint.o \
	${OBJECTDIR}/constraint/LimitedTimeGroup.o \
	${OBJECTDIR}/constraint/LinkEventsConstraint.o \
	${OBJECTDIR}/constraint/OrderEventsConstraint.o \
	${OBJECTDIR}/constraint/PreferResourcesConstraint.o \
	${OBJECTDIR}/constraint/PreferTimesConstraint.o \
	${OBJECTDIR}/constraint/SplitEventsConstraint.o \
	${OBJECTDIR}/constraint/SpreadEventsConstraint.o \
	${OBJECTDIR}/exception/InvalidObjectConversion.o \
	${OBJECTDIR}/exception/ObjectCreation.o \
	${OBJECTDIR}/exception/ObjectTypeMismatch.o \
	${OBJECTDIR}/exception/RequestedObjectNotFound.o \
	${OBJECTDIR}/internal/PossibleDummy.o \
	${OBJECTDIR}/internal/Util.o \
	${OBJECTDIR}/internal/global.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-fPIC
CXXFLAGS=-fPIC

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../lib/khe ../../lib/khe/so/khe_archive.so ../../lib/khe/so/khe_archive_metadata.so ../../lib/khe/so/khe_assign_resource_constraint.so ../../lib/khe/so/khe_assign_resource_monitor.so ../../lib/khe/so/khe_assign_time_constraint.so ../../lib/khe/so/khe_assign_time_monitor.so ../../lib/khe/so/khe_avoid_clashes_constraint.so ../../lib/khe/so/khe_avoid_clashes_monitor.so ../../lib/khe/so/khe_avoid_split_assignments_constraint.so ../../lib/khe/so/khe_avoid_split_assignments_monitor.so ../../lib/khe/so/khe_avoid_unavailable_times_constraint.so ../../lib/khe/so/khe_avoid_unavailable_times_monitor.so ../../lib/khe/so/khe_cluster_busy_times_constraint.so ../../lib/khe/so/khe_cluster_busy_times_monitor.so ../../lib/khe/so/khe_constraint.so ../../lib/khe/so/khe_cycle_meet.so ../../lib/khe/so/khe_distribute_split_events_constraint.so ../../lib/khe/so/khe_distribute_split_events_monitor.so ../../lib/khe/so/khe_evenness_handler.so ../../lib/khe/so/khe_evenness_monitor.so ../../lib/khe/so/khe_event.so ../../lib/khe/so/khe_event_group.so ../../lib/khe/so/khe_event_in_soln.so ../../lib/khe/so/khe_event_resource.so ../../lib/khe/so/khe_event_resource_group.so ../../lib/khe/so/khe_event_resource_in_soln.so ../../lib/khe/so/khe_group_monitor.so ../../lib/khe/so/khe_instance.so ../../lib/khe/so/khe_instance_metadata.so ../../lib/khe/so/khe_layer.so ../../lib/khe/so/khe_limit_busy_times_constraint.so ../../lib/khe/so/khe_limit_busy_times_monitor.so ../../lib/khe/so/khe_limit_idle_times_constraint.so ../../lib/khe/so/khe_limit_idle_times_monitor.so ../../lib/khe/so/khe_limit_workload_constraint.so ../../lib/khe/so/khe_limit_workload_monitor.so ../../lib/khe/so/khe_link_events_constraint.so ../../lib/khe/so/khe_link_events_monitor.so ../../lib/khe/so/khe_lset.so ../../lib/khe/so/khe_mark.so ../../lib/khe/so/khe_matching.so ../../lib/khe/so/khe_meet.so ../../lib/khe/so/khe_meet_bound.so ../../lib/khe/so/khe_monitor.so ../../lib/khe/so/khe_node.so ../../lib/khe/so/khe_order_events_constraint.so ../../lib/khe/so/khe_order_events_monitor.so ../../lib/khe/so/khe_ordinary_demand_monitor.so ../../lib/khe/so/khe_part_graph.so ../../lib/khe/so/khe_partition.so ../../lib/khe/so/khe_path.so ../../lib/khe/so/khe_prefer_resources_constraint.so ../../lib/khe/so/khe_prefer_resources_monitor.so ../../lib/khe/so/khe_prefer_times_constraint.so ../../lib/khe/so/khe_prefer_times_monitor.so ../../lib/khe/so/khe_priqueue.so ../../lib/khe/so/khe_resource.so ../../lib/khe/so/khe_resource_group.so ../../lib/khe/so/khe_resource_in_soln.so ../../lib/khe/so/khe_resource_type.so ../../lib/khe/so/khe_se_ejector.so ../../lib/khe/so/khe_se_primary.so ../../lib/khe/so/khe_se_secondary.so ../../lib/khe/so/khe_se_solvers.so ../../lib/khe/so/khe_sl_assigned_split_job.so ../../lib/khe/so/khe_sl_avoid_clashes_split_job.so ../../lib/khe/so/khe_sl_distribute_split_job.so ../../lib/khe/so/khe_sl_domain_split_job.so ../../lib/khe/so/khe_sl_layer_tree.so ../../lib/khe/so/khe_sl_link_split_job.so ../../lib/khe/so/khe_sl_pack_split_job.so ../../lib/khe/so/khe_sl_preassigned_split_job.so ../../lib/khe/so/khe_sl_split_class.so ../../lib/khe/so/khe_sl_split_forest.so ../../lib/khe/so/khe_sl_split_job.so ../../lib/khe/so/khe_sl_split_layer.so ../../lib/khe/so/khe_sl_split_split_job.so ../../lib/khe/so/khe_sl_spread_split_job.so ../../lib/khe/so/khe_sm_backoff.so ../../lib/khe/so/khe_sm_benchmark.so ../../lib/khe/so/khe_sm_general_solve.so ../../lib/khe/so/khe_sm_options.so ../../lib/khe/so/khe_sm_parallel_solve.so ../../lib/khe/so/khe_sm_stats.so ../../lib/khe/so/khe_sm_workload.so ../../lib/khe/so/khe_soln.so ../../lib/khe/so/khe_soln_group.so ../../lib/khe/so/khe_soln_group_metadata.so ../../lib/khe/so/khe_split_events_constraint.so ../../lib/khe/so/khe_split_events_monitor.so ../../lib/khe/so/khe_spread_events_constraint.so ../../lib/khe/so/khe_spread_events_monitor.so ../../lib/khe/so/khe_sr_combined.so ../../lib/khe/so/khe_sr_first_resource.so ../../lib/khe/so/khe_sr_invariant.so ../../lib/khe/so/khe_sr_kempe.so ../../lib/khe/so/khe_sr_pack_resource.so ../../lib/khe/so/khe_sr_rematch.so ../../lib/khe/so/khe_sr_resource_pair.so ../../lib/khe/so/khe_sr_split_resource.so ../../lib/khe/so/khe_sr_task_bound_group.so ../../lib/khe/so/khe_sr_task_group.so ../../lib/khe/so/khe_sr_task_tree.so ../../lib/khe/so/khe_ss_grouping.so ../../lib/khe/so/khe_ss_layers.so ../../lib/khe/so/khe_ss_misc.so ../../lib/khe/so/khe_ss_nodes.so ../../lib/khe/so/khe_ss_runarounds.so ../../lib/khe/so/khe_ss_splits.so ../../lib/khe/so/khe_ss_time_equiv.so ../../lib/khe/so/khe_ss_zones.so ../../lib/khe/so/khe_st_basic.so ../../lib/khe/so/khe_st_cluster_and_limit.so ../../lib/khe/so/khe_st_combined.so ../../lib/khe/so/khe_st_domain.so ../../lib/khe/so/khe_st_elm_core.so ../../lib/khe/so/khe_st_elm_irregular.so ../../lib/khe/so/khe_st_elm_node.so ../../lib/khe/so/khe_st_elm_split.so ../../lib/khe/so/khe_st_helper.so ../../lib/khe/so/khe_st_kempe.so ../../lib/khe/so/khe_st_layer_asst.so ../../lib/khe/so/khe_st_layer_node_match.so ../../lib/khe/so/khe_st_layered.so ../../lib/khe/so/khe_st_meet_bound_group.so ../../lib/khe/so/khe_st_meet_set_repair.so ../../lib/khe/so/khe_st_runaround.so ../../lib/khe/so/khe_st_tree_repair.so ../../lib/khe/so/khe_task.so ../../lib/khe/so/khe_task_bound.so ../../lib/khe/so/khe_tasking.so ../../lib/khe/so/khe_time.so ../../lib/khe/so/khe_time_group.so ../../lib/khe/so/khe_time_group_monitor.so ../../lib/khe/so/khe_time_group_nhood.so ../../lib/khe/so/khe_timetable_monitor.so ../../lib/khe/so/khe_trace.so ../../lib/khe/so/khe_wmatch.so ../../lib/khe/so/khe_workload_demand_monitor.so ../../lib/khe/so/khe_zone.so ../../lib/khe/so/kml.so -lpthread ../../lib/khe/so/m.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_archive.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_archive_metadata.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_assign_resource_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_assign_resource_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_assign_time_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_assign_time_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_avoid_clashes_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_avoid_clashes_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_avoid_split_assignments_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_avoid_split_assignments_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_avoid_unavailable_times_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_avoid_unavailable_times_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_cluster_busy_times_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_cluster_busy_times_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_cycle_meet.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_distribute_split_events_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_distribute_split_events_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_evenness_handler.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_evenness_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_event.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_event_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_event_in_soln.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_event_resource.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_event_resource_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_event_resource_in_soln.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_group_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_instance.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_instance_metadata.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_layer.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_limit_busy_times_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_limit_busy_times_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_limit_idle_times_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_limit_idle_times_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_limit_workload_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_limit_workload_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_link_events_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_link_events_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_lset.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_mark.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_matching.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_meet.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_meet_bound.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_node.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_order_events_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_order_events_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ordinary_demand_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_part_graph.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_partition.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_path.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_prefer_resources_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_prefer_resources_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_prefer_times_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_prefer_times_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_priqueue.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_resource.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_resource_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_resource_in_soln.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_resource_type.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_se_ejector.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_se_primary.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_se_secondary.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_se_solvers.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_assigned_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_avoid_clashes_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_distribute_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_domain_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_layer_tree.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_link_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_pack_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_preassigned_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_split_class.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_split_forest.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_split_layer.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_split_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sl_spread_split_job.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sm_backoff.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sm_benchmark.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sm_general_solve.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sm_options.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sm_parallel_solve.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sm_stats.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sm_workload.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_soln.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_soln_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_soln_group_metadata.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_split_events_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_split_events_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_spread_events_constraint.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_spread_events_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_combined.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_first_resource.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_invariant.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_kempe.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_pack_resource.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_rematch.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_resource_pair.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_split_resource.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_task_bound_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_task_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_sr_task_tree.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_grouping.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_layers.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_misc.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_nodes.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_runarounds.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_splits.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_time_equiv.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_ss_zones.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_basic.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_cluster_and_limit.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_combined.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_domain.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_elm_core.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_elm_irregular.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_elm_node.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_elm_split.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_helper.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_kempe.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_layer_asst.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_layer_node_match.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_layered.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_meet_bound_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_meet_set_repair.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_runaround.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_st_tree_repair.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_task.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_task_bound.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_tasking.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_time.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_time_group.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_time_group_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_time_group_nhood.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_timetable_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_trace.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_wmatch.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_workload_demand_monitor.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/khe_zone.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/kml.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ../../lib/khe/so/m.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib ${OBJECTFILES} ${LDLIBSOPTIONS} -lexpat -lgtest

${OBJECTDIR}/base/cost/Cost.o: base/cost/Cost.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/cost
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/cost/Cost.o base/cost/Cost.cpp

${OBJECTDIR}/base/cost/CostFunction.o: base/cost/CostFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/cost
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/cost/CostFunction.o base/cost/CostFunction.cpp

${OBJECTDIR}/base/event/Event.o: base/event/Event.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/event
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/event/Event.o base/event/Event.cpp

${OBJECTDIR}/base/event/EventGroup.o: base/event/EventGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/event
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/event/EventGroup.o base/event/EventGroup.cpp

${OBJECTDIR}/base/event/EventGroupKind.o: base/event/EventGroupKind.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/event
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/event/EventGroupKind.o base/event/EventGroupKind.cpp

${OBJECTDIR}/base/event/EventResource.o: base/event/EventResource.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/event
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/event/EventResource.o base/event/EventResource.cpp

${OBJECTDIR}/base/event/EventResourceGroup.o: base/event/EventResourceGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/event
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/event/EventResourceGroup.o base/event/EventResourceGroup.cpp

${OBJECTDIR}/base/event/SubEvent.o: base/event/SubEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/event
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/event/SubEvent.o base/event/SubEvent.cpp

${OBJECTDIR}/base/file/Archive.o: base/file/Archive.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/file
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/file/Archive.o base/file/Archive.cpp

${OBJECTDIR}/base/file/ArchiveMetaData.o: base/file/ArchiveMetaData.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/file
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/file/ArchiveMetaData.o base/file/ArchiveMetaData.cpp

${OBJECTDIR}/base/file/Instance.o: base/file/Instance.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/file
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/file/Instance.o base/file/Instance.cpp

${OBJECTDIR}/base/file/InstanceMetaData.o: base/file/InstanceMetaData.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/file
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/file/InstanceMetaData.o base/file/InstanceMetaData.cpp

${OBJECTDIR}/base/resource/Resource.o: base/resource/Resource.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/resource
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/resource/Resource.o base/resource/Resource.cpp

${OBJECTDIR}/base/resource/ResourceGroup.o: base/resource/ResourceGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/resource
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/resource/ResourceGroup.o base/resource/ResourceGroup.cpp

${OBJECTDIR}/base/resource/ResourceType.o: base/resource/ResourceType.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/resource
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/resource/ResourceType.o base/resource/ResourceType.cpp

${OBJECTDIR}/base/solution/Solution.o: base/solution/Solution.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/solution
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/solution/Solution.o base/solution/Solution.cpp

${OBJECTDIR}/base/solution/SolutionGroup.o: base/solution/SolutionGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/solution
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/solution/SolutionGroup.o base/solution/SolutionGroup.cpp

${OBJECTDIR}/base/solution/SolutionGroupMetaData.o: base/solution/SolutionGroupMetaData.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/solution
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/solution/SolutionGroupMetaData.o base/solution/SolutionGroupMetaData.cpp

${OBJECTDIR}/base/solution/Task.o: base/solution/Task.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/solution
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/solution/Task.o base/solution/Task.cpp

${OBJECTDIR}/base/tests.o: base/tests.cpp 
	${MKDIR} -p ${OBJECTDIR}/base
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/tests.o base/tests.cpp

${OBJECTDIR}/base/time/Meet.o: base/time/Meet.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/time
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/time/Meet.o base/time/Meet.cpp

${OBJECTDIR}/base/time/Time.o: base/time/Time.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/time
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/time/Time.o base/time/Time.cpp

${OBJECTDIR}/base/time/TimeGroup.o: base/time/TimeGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/time
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/time/TimeGroup.o base/time/TimeGroup.cpp

${OBJECTDIR}/base/time/TimeSpread.o: base/time/TimeSpread.cpp 
	${MKDIR} -p ${OBJECTDIR}/base/time
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/base/time/TimeSpread.o base/time/TimeSpread.cpp

${OBJECTDIR}/constraint/AssignResourceConstraint.o: constraint/AssignResourceConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/AssignResourceConstraint.o constraint/AssignResourceConstraint.cpp

${OBJECTDIR}/constraint/AssignTimeConstraint.o: constraint/AssignTimeConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/AssignTimeConstraint.o constraint/AssignTimeConstraint.cpp

${OBJECTDIR}/constraint/AvoidClashesConstraint.o: constraint/AvoidClashesConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/AvoidClashesConstraint.o constraint/AvoidClashesConstraint.cpp

${OBJECTDIR}/constraint/AvoidSplitAssignmentsConstraint.o: constraint/AvoidSplitAssignmentsConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/AvoidSplitAssignmentsConstraint.o constraint/AvoidSplitAssignmentsConstraint.cpp

${OBJECTDIR}/constraint/AvoidUnavailableTimesConstraint.o: constraint/AvoidUnavailableTimesConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/AvoidUnavailableTimesConstraint.o constraint/AvoidUnavailableTimesConstraint.cpp

${OBJECTDIR}/constraint/ClusterBusyTimesConstraint.o: constraint/ClusterBusyTimesConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/ClusterBusyTimesConstraint.o constraint/ClusterBusyTimesConstraint.cpp

${OBJECTDIR}/constraint/Constraint.o: constraint/Constraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/Constraint.o constraint/Constraint.cpp

${OBJECTDIR}/constraint/DistributeSplitEventsConstraint.o: constraint/DistributeSplitEventsConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/DistributeSplitEventsConstraint.o constraint/DistributeSplitEventsConstraint.cpp

${OBJECTDIR}/constraint/LimitBusyTimesConstraint.o: constraint/LimitBusyTimesConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/LimitBusyTimesConstraint.o constraint/LimitBusyTimesConstraint.cpp

${OBJECTDIR}/constraint/LimitIdleTimesConstraint.o: constraint/LimitIdleTimesConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/LimitIdleTimesConstraint.o constraint/LimitIdleTimesConstraint.cpp

${OBJECTDIR}/constraint/LimitWorkloadConstraint.o: constraint/LimitWorkloadConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/LimitWorkloadConstraint.o constraint/LimitWorkloadConstraint.cpp

${OBJECTDIR}/constraint/LimitedTimeGroup.o: constraint/LimitedTimeGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/LimitedTimeGroup.o constraint/LimitedTimeGroup.cpp

${OBJECTDIR}/constraint/LinkEventsConstraint.o: constraint/LinkEventsConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/LinkEventsConstraint.o constraint/LinkEventsConstraint.cpp

${OBJECTDIR}/constraint/OrderEventsConstraint.o: constraint/OrderEventsConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/OrderEventsConstraint.o constraint/OrderEventsConstraint.cpp

${OBJECTDIR}/constraint/PreferResourcesConstraint.o: constraint/PreferResourcesConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/PreferResourcesConstraint.o constraint/PreferResourcesConstraint.cpp

${OBJECTDIR}/constraint/PreferTimesConstraint.o: constraint/PreferTimesConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/PreferTimesConstraint.o constraint/PreferTimesConstraint.cpp

${OBJECTDIR}/constraint/SplitEventsConstraint.o: constraint/SplitEventsConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/SplitEventsConstraint.o constraint/SplitEventsConstraint.cpp

${OBJECTDIR}/constraint/SpreadEventsConstraint.o: constraint/SpreadEventsConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/constraint
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/constraint/SpreadEventsConstraint.o constraint/SpreadEventsConstraint.cpp

${OBJECTDIR}/exception/InvalidObjectConversion.o: exception/InvalidObjectConversion.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/InvalidObjectConversion.o exception/InvalidObjectConversion.cpp

${OBJECTDIR}/exception/ObjectCreation.o: exception/ObjectCreation.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/ObjectCreation.o exception/ObjectCreation.cpp

${OBJECTDIR}/exception/ObjectTypeMismatch.o: exception/ObjectTypeMismatch.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/ObjectTypeMismatch.o exception/ObjectTypeMismatch.cpp

${OBJECTDIR}/exception/RequestedObjectNotFound.o: exception/RequestedObjectNotFound.cpp 
	${MKDIR} -p ${OBJECTDIR}/exception
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/exception/RequestedObjectNotFound.o exception/RequestedObjectNotFound.cpp

${OBJECTDIR}/internal/PossibleDummy.o: internal/PossibleDummy.cpp 
	${MKDIR} -p ${OBJECTDIR}/internal
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/internal/PossibleDummy.o internal/PossibleDummy.cpp

${OBJECTDIR}/internal/Util.o: internal/Util.cpp 
	${MKDIR} -p ${OBJECTDIR}/internal
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/internal/Util.o internal/Util.cpp

${OBJECTDIR}/internal/global.o: internal/global.cpp 
	${MKDIR} -p ${OBJECTDIR}/internal
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/internal/global.o internal/global.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ibase -Ibase/cost -Ibase/file -Ibase/file -Ibase/resource -Ibase/solution -Ibase/time -Iconstraint -Iconstraint/abstract -Iexception -Iinternal -I../../lib/khe -Ibase/event -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/khelib

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
